#include "Date.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "utils.h"

Date::Date() {}
Date::Date(int date, int month, int year) {
    if (year < MIN_YEAR) {
        std::cerr << "Invalid year";
    }
    if (month < 1 || month > 12) {
        std::cerr << "Invalid month";
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (date < 1 || date > 31) {
            std::cerr << "Invalid date";
        }
    } else if (month == 2) {
        if (year % 4 == 0) {
            if (date < 1 || date > 29) {
                std::cerr << "Invalid date";
            }
        } else {
            if (date < 1 || date > 28) {
                std::cerr << "Invalid date";
            }
        }
    } else {
        if (date < 1 || date > 30) {
            std::cerr << "Invalid date";
        }
    }
    this->date = date;
    this->month = month;
    this->year = year;
}
bool Date::operator>(Date d2) {
    if (this->year > d2.year) {
        return true;
    } else if (this->year == d2.year) {
        if (this->month > d2.month) {
            return true;

        } else if (this->month == d2.month) {
            if (this->date > d2.date) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
bool Date::operator<(Date d2) {
    if (this->date != d2.date || this->month != d2.month || this->year != d2.year) {
        if (!(*this > d2)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

}

bool Date::operator==(Date d2) {
    if (!(*this > d2) && !(*this < d2)) {
        return true;
    } else {
        return false;
    }
}
int Date::operator - (Date d2) {
    if (*this == d2) {
        return 0;
    }
    if (*this > d2) {
        if (this->year == d2.year || this->year % 4 == 0) {
            if (this->month == d2.month) {
                return this->date - d2.date + 1;
            } else {
                return this->date + leap_year_date_map[d2.month] - d2.date + 1;
            }
        } else if (this->year == d2.year || this->year % 4 != 0) {
            if (this->month == d2.month) {
                return this->date - d2.date + 1;
            } else {
                return this->date + normal_year_date_map[d2.month] - d2.date + 1;
            }
        } else {
            int gap = this->year - d2.year - 1;
            int numDaysInGap = 0;
            int headMonthDays = 0;
            int tailMonthDays = 0;
            for (int i = d2.year + 1; i < this->year; i++) {
                if (i % 4 == 0) {
                    numDaysInGap += 366;
                } else {
                    numDaysInGap += 365;
                }
            }
            if (this->year % 4 == 0 && d2.year % 4 == 0) {
                for (int i = d2.month + 1; i < 13; i++) {
                    headMonthDays += leap_year_date_map[i];
                }
                for (int i = 1; i < this->month; i++) {
                    tailMonthDays += leap_year_date_map[i];
                }

            } else if (this->year % 4 == 0 && d2.year % 4 != 0) {
                for (int i = d2.month + 1; i < 13; i++) {
                    headMonthDays += normal_year_date_map[i];
                }
                for (int i = 1; i < this->month; i++) {
                    tailMonthDays += leap_year_date_map[i];
                }
            } else {
                for (int i = d2.month + 1; i < 13; i++) {
                    headMonthDays += normal_year_date_map[i];
                }
                for (int i = 1; i < this->month; i++) {
                    tailMonthDays += normal_year_date_map[i];
                }
            }
            return numDaysInGap + headMonthDays + tailMonthDays + leap_year_date_map[d2.month] - d2.date + 1 + this->date;
        }
    }
    return -1;
}
std::string Date::date_to_string(Date* dmy) {
    std::string result = "";
    std::string date;
    std::string month;
    std::string year = std::to_string(dmy->year);
    if (dmy->date < 10) {
        date = "0" + std::to_string(dmy->date);
    }
    if (dmy->month < 10) {
        month = "0" + std::to_string(dmy->month);
    }
    result = date + "/" + month + "/" + year;

    return result;
}

Date Date::string_to_date(std::string str) {
    std::vector<std::string> list = split(str, '/');
    int date = std::stoi(list[0]);
    int month = std::stoi(list[1]);
    int year = std::stoi(list[2]);
    return Date(date, month, year);
}
