/**
 * Project Untitled
 */

#include "HouseDatabase.h"
#include <iostream>

/**
 * HouseDatabase implementation
 */

/**
 * @param data
 * @return vector<string>
 */
vector<string> HouseDatabase::readHouse(map<string, string> data) {
    // if data is EMPTY, NOT NULL return all data
    vector<string> result;
    // check if data is empty
    if (data.empty()) {
        for (int i = 0; i < houses.size(); i++) {
            result.push_back(houses[i]->toString());
        }

    } else {
        Date start = Date::string_to_date(std::any_cast<string>(data["start"]));
        Date end = Date::string_to_date(std::any_cast<string>(data["end"]));
        for (int i = 0; i < houses.size(); i++) {
            if (start == houses[i]->getStartDate() && end == houses[i]->getEndDate()) {
                if (data.find("city") == data.end()) {
                    result.push_back(houses[i]->toString());
                } else {
                    if (std::any_cast<string>(data["city"]) == houses[i]->getCity()) {
                        result.push_back(houses[i]->toString());
                    }
                }
            }
        }
    }

    return result;
}

/**
 * @param data
 * @return bool
 */
bool HouseDatabase::createHouse(map<string, string> data) {
    return false;
}

/**
 * @param hID
 * @return House *
 */
House* HouseDatabase::findHouse(string hID) {
    return nullptr;
}

/**
 * @param data
 */
HouseDatabase::HouseDatabase(vector<string> data) {
    for (int i = 0; i < data.size(); i++) {
        House house = House(data[i]);

        houses.push_back(&house);
    }
}