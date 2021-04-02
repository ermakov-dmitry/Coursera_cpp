//
// Created by dmitry on 04.01.2021.
//

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Date {
public:
    Date(int new_year, int new_month, int new_day);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& is);
