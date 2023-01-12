#include "Date.h"

#include <iostream>

#include "utils.h"

Date::Date() {
    empty = true;
}
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
    if (d2.isEmpty() || this->isEmpty()) {
        return false;
    }
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
    if (d2.isEmpty() || this->isEmpty()) return false;
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
bool Date::operator>=(Date d2) {
    if (d2.isEmpty() || this->isEmpty()) return false;
    if (*this > d2 || *this == d2) {
        return true;
    }
    return false;
}
bool Date::operator<=(Date d2) {
    if (d2.isEmpty() || this->isEmpty()) return false;
    if (*this < d2 || *this == d2) {
        return true;
    }
    return false;
}
int Date::rdn(int d, int m, int y) {
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

int Date::operator-(Date d2) {
    return rdn(this->date, this->month, this->year) - rdn(d2.date, d2.month, d2.year) + 1;
}
std::string Date::dateToString(Date* dmy) {
    std::string result = "";
    std::string date;
    std::string month;
    std::string year = std::to_string(dmy->year);
    if (dmy->date < 10) {
        date = "0" + std::to_string(dmy->date);
    } else {
        date = std::to_string(dmy->date);
    }
    if (dmy->month < 10) {
        month = "0" + std::to_string(dmy->month);
    } else {
        month = std::to_string(dmy->month);
    }
    result = date + "/" + month + "/" + year;

    return result;
}

Date Date::stringToDate(std::string str) {
    if (str == "") return Date();
    std::vector<std::string> list = split(str, '/');
    int date = std::stoi(list[0]);
    int month = std::stoi(list[1]);

    int year = std::stoi(list[2]);
    return Date(date, month, year);
}

void Date::setEmpty() {
    empty = true;
}

bool Date::isEmpty() {
    return empty;
}