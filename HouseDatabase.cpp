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
vector<string> HouseDatabase::readHouse(map<string, any> data) {
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
bool HouseDatabase::createHouse(map<string, any> data) {
    int hID = std::any_cast<int>(data["hID"]);
    string description = std::any_cast<string>(data["description"]);
    string city = std::any_cast<string>(data["city"]);
    int houseRating = std::any_cast<int>(data["houseRating"]);
    Date start = std::any_cast<Date>(data["start"]);
    Date end = std::any_cast<Date>(data["end"]);
    int consumingPoint = std::any_cast<int>(data["consumingPoint"]);
    int minOccupierRating = std::any_cast<int>(data["minOccupierRating"]);
    vector<vector<string>> reviews = std::any_cast<vector<vector<string>>>(data["reviews"]);
    House* house = new House(hID, description, city, houseRating, start, end, consumingPoint, minOccupierRating, reviews);

    return false;
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