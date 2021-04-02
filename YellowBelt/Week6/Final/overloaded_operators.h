//
// Created by dmitry on 08.01.2021.
//

#pragma once
#include "date.h"
#include <vector>
#include <map>
#include <utility>

bool operator < (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
ostream& operator << (ostream& stream, const Date& date);
template <class K, class V>
ostream& operator << (ostream& os, const map<K, vector<V>>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}
template <class K, class V>
ostream& operator << (ostream& os, const pair<K, vector<V>>& p) {
    for (auto it = p.second.begin(); it != p.second.end(); it++) {
        os << p.first << ' ' << *it;
        if (it != prev(p.second.end())) {
            os << endl;
        }
    }
    return os;
}
template <class T>
ostream& operator << (ostream& os, const vector<T> vec) {
    os << '{';
    for (auto it = vec.begin(); it != vec.end(); it++) {
        os << *it;
        if (it != prev(vec.end())) {
            os << ", ";
        }
    }
    return os << '}';
}
template <class K, class V>
ostream& operator << (ostream& os, const pair<K, V> p) {
    return os << p.first << ' ' << p.second;
}
