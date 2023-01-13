/**
 * Project Untitled
 */

#include "HouseDatabase.h"

/**
 * HouseDatabase implementation
 */

HouseDatabase::~HouseDatabase() {
    for (int i = houses.size() - 1; i >= 0; i--) {
        delete houses[i];
    }
}
/**
 * @param data
 * @return vector<House*>
 */
vector<House*> HouseDatabase::readHousePointers(map<string, string> data) {
    vector<House*> result;
    // check if data is empty
    string emptyMark;
    string hID;
    string city;
    double hRating;
    Date start, end;
    int consumingPoint;
    double minRating;

    if (data.empty()) {
        for (int i = 0; i < houses.size(); i++) {
            result.push_back(houses[i]);
        }
    } else {
        if (data.count("hID") == 0) {
            data["hID"] = emptyMark;
        } else {
            hID = data["hID"];
        }
        if (data.count("city") == 0) {
            data["city"] = emptyMark;
        } else {
            city = data["city"];
        }

        if (data.count("minRating") == 0) {
            data["minRating"] = emptyMark;
        } else {
            minRating = std::stod(data["minRating"]);
        }
        if (data.count("hRating") == 0) {
            data["hRating"] = emptyMark;
        } else {
            hRating = std::stod(data["hRating"]);
        }
        if (data.count("consumingPoint") == 0) {
            data["consumingPoint"] = emptyMark;
        } else {
            consumingPoint = std::stoi(data["consumingPoint"]);
        }
        if (data.count("start") == 0) {
            data["start"] = emptyMark;
        } else {
            start = Date::stringToDate(data["start"]);
        }
        if (data.count("end") == 0) {
            data["end"] = emptyMark;
        } else {
            end = Date::stringToDate(data["end"]);
        }

        for (House* house : houses) {
            if (
                (house->getID() == hID || data["hID"] == emptyMark) &&
                (house->getCity() == city || data["city"] == emptyMark) &&
                (house->getMinOccupierRating() == minRating || data["minRating"] == emptyMark) &&
                (house->getHouseRating() == hRating || data["hRating"] == emptyMark) &&
                (house->getConsumingPoints() == consumingPoint || data["consumingPoint"] == emptyMark) &&
                (house->getStartDate() <= start || data["start"] == emptyMark) &&
                (house->getEndDate() >= end || data["end"] == emptyMark)

            ) {
                result.push_back(house);
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
        string hID = std::to_string(houses.size() + 1);
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
House* HouseDatabase::findHouse(string hID) {
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
    House* house;
    for (int i = 0; i < data.size(); i++) {
        house = new House(data[i]);

        houses.push_back(house);
    }
}