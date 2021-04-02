//
// Created by dmitry on 04.01.2021.
//

#include "database.h"

void Database::Add(const Date &date, const string &event) {
    if (storage[date].count(event) == 0) {
        storage[date].insert(event);
        unsort_storage[date].push_back(event);
    }
}

void Database::Print(ostream &stream) const {
    for (const auto& st : unsort_storage) {
        stream << st << endl;
    }
}

pair<Date, string> Database::Last(const Date &date) const {
    if (unsort_storage.empty()) {
        throw invalid_argument("no entries");
    }
    auto it = unsort_storage.upper_bound(date);
    if (it == unsort_storage.begin()) {
        throw invalid_argument("no entries");
    }
    return {prev(it)->first, *prev(prev(it)->second.end())};
}
