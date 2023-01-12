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
    bool empty = false;
    static const int MIN_YEAR = 2022;

    Date();
    Date(int date, int month, int year);
    bool operator>(Date d2);
    bool operator<(Date d2);
    bool operator==(Date d2);
    bool operator>=(Date d2);
    bool operator<=(Date d2);
    int rdn(int d, int m, int y);
    int operator-(Date d2);
    void setEmpty();
    bool isEmpty();
    static std::string dateToString(Date* dmy);
    static Date stringToDate(std::string str);
};

#endif