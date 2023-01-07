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
 * @return vector<House*>
 */
vector<House*> HouseDatabase::readHousePointers(map<string, string> data) {
    vector<House*> result;
    // check if data is empty
    if (data.empty()) {
        for (int i = 0; i < houses.size(); i++) {
            result.push_back(houses[i]);
        }

    } else {
        Date start = Date::string_to_date(data["start"]);
        Date end = Date::string_to_date(data["end"]);
        for (int i = 0; i < houses.size(); i++) {
            if (start <= houses[i]->getStartDate() && end >= houses[i]->getEndDate()) {
                if (data.find("city") == data.end()) {
                    result.push_back(houses[i]);
                } else {
                    if (data["city"] == houses[i]->getCity()) {
                        result.push_back(houses[i]);
                    }
                }
            }
        }
    }
    return result;
}

/**
 * @param data
 * @return vector<string>
 */
vector<string> HouseDatabase::readHouse(map<string, string> data) {
    // if data is EMPTY, NOT NULL return all data
    vector<string> result;

    vector<House*> housePointers = this->readHousePointers(data);
    for (House* house : housePointers) {
        result.push_back(house->toString());
    }

    return result;
}

/**
 * @param data
 * @return bool
 */
bool HouseDatabase::createHouse(map<string, string> data) {
    try {
        int hID = houses.size() + 1;
        string description = data["description"];
        string city = data["city"];

        House* house = new House(hID, description, city);
        houses.push_back(house);
    } catch (std::bad_alloc) {
        return false;
    }

    return true;
}

/**
 * @param hID
 * @return House *
 */
House* HouseDatabase::findHouse(int hID) {
    for (int i = 0; i < houses.size(); i++) {
        if (houses[i]->getID() == hID) {
            return houses[i];
        }
    }
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