/**
 * Project Untitled
 */

#include "HouseDatabase.h"

/**
 * HouseDatabase implementation
 */

/**
 * @param data
 * @return vector<string>
 */
vector<string> HouseDatabase::readHouse(map<string, any> data) {
    vector<string> result;

    Date start = Date::string_to_date(std::any_cast<string>(data["start"]));
    Date end = Date::string_to_date(std::any_cast<string>(data["end"]));
    for (int i = 0; i < houses.size(); i++) {
        if (start == houses[i]->start && end == houses[i]->end && data["city"]) {
            if (data.find("city") == data.end()) {
                result.push_back(houses[i]->toString());
            } else {
                if (data["city"] == houses[i]->city) {
                    result.push_back(houses[i]->toString());
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
        // vector<string> attributes = split(data[i], ',');
        House house = House(data[i]);

        houses.push_back(&house);
    }
}