#include "utils.h"
#include <iostream>
std::vector<std::string> split(std::string test, char delimiter) {
    std::stringstream ss;
    ss << test;
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, delimiter)) {
        seglist.push_back(segment);
    }
    return seglist;
}

std::string join(std::vector<std::string> list, char joinChar) {
    std::string result = list[0];
    for (int i = 1; i < list.size(); i++) {
        std::string s(1, joinChar);

        result.append(s);

        result.append(list[i]);

    }
    return result;
}

std::vector<std::string> extractData(std::ifstream& data) {
    std::vector<std::string> result;

    std::string mid;
    int count = 0;

    while (!data.eof()) {
            std::getline(data, mid);
            if (mid.empty()) {
                return result;
            }
            result.push_back(mid);
            count++;
            
    }
    return result;
}
// code reference: https://stackoverflow.com/questions/3108454/validation-for-phone-number-and-mobile-number
bool validPhoneNumber(std::string phonenumber) {
    // for mobile phone with 10 digits
    if (phonenumber.size() != 10) return false; 
    if (phonenumber.at(0) != '0') return false;
    for (int i = 0; i < phonenumber.size(); i++) {
        if (phonenumber.at(i) < '0' || phonenumber.at(i) > '9') return false;
    }

    return true;
}
