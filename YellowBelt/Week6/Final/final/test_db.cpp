//
// Created by dmitry on 06.01.2021.
//

#include "test_db.h"
#include "condition_parser.h"

int DoRemove (Database& db, const string& str) {
    istringstream is (str);
    auto condition = ParseCondition(is);
    auto predicate = [condition](const Date &date, const string &event) {
        return condition->Evaluate(date, event);
    };
    return db.RemoveIf(predicate);
}

string DoFind (Database& db, const string& str) {
    istringstream is (str);
    auto condition = ParseCondition(is);
    auto predicate = [condition](const Date &date, const string &event) {
        return condition->Evaluate(date, event);
    };
    const auto entries = db.FindIf(predicate);
    ostringstream os;
    for (const auto& entry : entries) {
        os << entry << endl;
    }
    os << entries.size();
    return os.str();
}

void TestAdd() {
    {
        {
            Database db;
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 7}, "xmas");
            ostringstream out;
            db.Print(out);
            AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n", out.str(), "straight ordering");
        }
        {
            Database db;
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 1}, "holiday");
            ostringstream out;
            db.Print(out);
            AssertEqual("2017-01-01 new year\n2017-01-01 holiday\n", out.str(), "several in one day");
        }
        {
            Database db;
            db.Add({2017, 1, 7}, "xmas");
            db.Add({2017, 1, 1}, "new year");
            ostringstream out;
            db.Print(out);
            AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n", out.str(), "reverse ordering");
        }
        {
            Database db;
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 1}, "xmas");
            db.Add({2017, 1, 1}, "new year");
            ostringstream out;
            db.Print(out);
            AssertEqual("2017-01-01 new year\n2017-01-01 xmas\n", out.str(), "uniq adding");
        }

    }

}

void TestFind() {
    {
        Database db;
        db.Add({2017, 1, 1}, "new year");
        db.Add({2017, 1, 7}, "xmas");
        AssertEqual("2017-01-01 new year\n1", DoFind(db, "date == 2017-01-01"), "simple find by date");
        AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n2", DoFind(db, "date < 2017-01-31"), "multiple find by date");
        AssertEqual("2017-01-01 new year\n1", DoFind(db, R"(event != "xmas")"), "multiple find by holiday");
    }
    {
        Database db;
        db.Add({2017, 1, 1}, "new year");
        db.Add({2017, 1, 1}, "new year2");
        db.Add({2017, 1, 7}, "xmas");
        AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n2", DoFind(db, R"(date == 2017-01-07 OR event == "new year")"),
                    "complex find or");
        AssertEqual("2017-01-01 new year\n1", DoFind(db, R"(date == 2017-01-01 AND event == "new year")"),
                    "complex find and");
        AssertEqual("0", DoFind(db, R"(date == 2017-01-09 AND event == "new year")"),
                    "complex find and, nothing");
    }
}

void TestDel() {
    {
        Database db;
        db.Add({2017, 1, 1}, "new year");
        db.Add({2017, 1, 7}, "xmas");
        AssertEqual(0, DoRemove(db, R"(event == "something")"), "Remove nothing");
        AssertEqual(1, DoRemove(db, R"(date == "2017-01-01")"), "Remove by date");
        ostringstream out;
        db.Print(out);
        AssertEqual("2017-01-07 xmas\n", out.str(), "Remove by date, left");
    }
    {
        Database db;
        db.Add({2017, 1, 1}, "new year");
        db.Add({2017, 1, 7}, "xmas");
        AssertEqual(1, DoRemove(db, R"(event == "xmas")"), "Remove by event");
        ostringstream out;
        db.Print(out);
        AssertEqual("2017-01-01 new year\n", out.str(), "Remove by event, left");
    }
    {
        Database db;
        db.Add({2017, 1, 1}, "new year");
        db.Add({2017, 1, 7}, "xmas");
        db.Add({2017, 1, 7}, "new year");
        AssertEqual(2, DoRemove(db, R"(event == "new year")"), "Multiple remove by event");
        ostringstream out;
        db.Print(out);
        AssertEqual("2017-01-07 xmas\n", out.str(), "Multiple remove by event, left");
    }
}

void TestLast() {
    Database db;
    db.Add({2017, 1, 1}, "new year");
    db.Add({2017, 1, 7}, "xmas");

    {
        try {
            db.Last({2016, 12, 31});
            Assert(false, "last, found no entries");
        } catch (...){
            Assert(true, "last, found no entries");

        }
    }
    {
        ostringstream os;
        os << db.Last({2017, 1, 2});
        AssertEqual("2017-01-01 new year", os.str(), "greater than date");
    }
    {
        ostringstream os;

        os << db.Last({2017, 1, 1});
        AssertEqual("2017-01-01 new year", os.str(), "eq to date");
    }
    {
        ostringstream os;
        os << db.Last({2017, 1, 10});
        AssertEqual("2017-01-07 xmas", os.str(), "greater than max date");
    }
}
