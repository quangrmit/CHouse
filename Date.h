#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Date {
   public:
    int date;
    int month;
    int year;
    static const int MIN_YEAR = 2022;
    std::unordered_map<int, int> normal_year_date_map{{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    std::unordered_map<int, int> leap_year_date_map{{1, 31}, {2, 29}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

    Date();
    Date(int date, int month, int year);
    bool operator>(Date d2);
    bool operator<(Date d2);
    bool operator==(Date d2);
    int operator-(Date d2);
    static std::string date_to_string(Date* dmy);
    static Date string_to_date(std::string str);
};

#endif