/**
 * Project Untitled
 */

#include "Authorization.h"

/**
 * Authorization implementation
 */

/**
 * @param username
 * @param password
 * @return Member *
 */
Authorization::Authorization() {}

Member* Authorization::login(string username, string password) {
    Database* database = Database::getInstance();
    MemberDatabase* members = database->getMemberDatabase();
    // may consider adding empty map to readMember();
    vector<string> results = members->readMember();
    string id = "";
    // Add default constructor for all classes
    Member* mid;
    for (int i = 0; i < results.size(); i++) {
        mid = new Member(results[i]);
        if (mid->compareUsernameandPassword(username, password)) {
            id = mid->getMid();
            break;
        }
    }
    // delete mid, database, members;

    if (id.empty()) return nullptr;
    return members->findMember(id);
}

/**
 * @param userData
 * @param houseData
 * @return bool
 */
bool Authorization::registerUser(map<string, string> userData, map<string, string> houseData) {
    Database* database = Database::getInstance();
    MemberDatabase* member = database->getMemberDatabase();
    HouseDatabase* house = database->getHouseDatabase();

    if (userData.count("fullname") == 0 || userData.count("username") == 0 || userData.count("password") == 0 || userData.count("phonenumber") == 0) return false;
    if (houseData.count("description") == 0 || houseData.count("city") == 0) return false;

    // city can only be sai gon, hue or ha noi

    if (houseData["city"] != "Sai Gon" && houseData["city"] != "Ha Noi" && houseData["city"] != "Hue") return false;

    if (!validPhoneNumber(userData["phonenumber"])) return false;
    bool result1 = member->createMember(userData);
    bool result2 = house->createHouse(houseData);
    // delete database, member, house;
    if (result1 && result2) return true;
    return false;
}

/**
 * @param username
 * @param password
 * @return Admin *
 */
Admin* Authorization::loginAdmin(string username, string password) {
    Database* database = Database::getInstance();
    Admin* result = database->getAdmin();
    if (result->compareUsernameandPassword(username, password)) {
        return result;
    }
    return nullptr;
}