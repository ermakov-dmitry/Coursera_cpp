//
// Created by dmitry on 08.01.2021.
//

#include "overloaded_operators.h"

bool operator < (const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator <= (const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator > (const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator >= (const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator == (const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator != (const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
           "-" << setw(2) << setfill('0') << date.GetMonth() <<
           "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}