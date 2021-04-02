//
// Created by dmitry on 04.01.2021.
//

#include "date.h"

Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}
int Date::GetDay() const {
    return day;
}

Date ParseDate(istream& date_stream) {
    bool ok = true;

    int year = 0;
    ok = ok && (date_stream >> year);
    // cerr << ok << ":" << year << endl;
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month = 0;
    ok = ok && (date_stream >> month);
    // cerr << ok << ":" << month << endl;
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day = 0;
    ok = ok && (date_stream >> day);
    // cerr << ok << ":" << day << endl;
    //ok = ok && (date_stream.peek() == ' ');

    if (!ok) {
        throw logic_error("Wrong date format");
    }
    return Date(year, month, day);
}