/**
 * Project Untitled
 */

#include "Admin.h"
#include <iostream>
/**
 * Admin implementation
 */



 Admin::Admin() {
    this->username = "admin";
    this->password = "123";
}

/**
 * @return vector<string>
 */
vector<string> Admin::viewAllHouse() {
    Database * database = Database::getInstance();
    HouseDatabase * houses = database->getHouseDatabase();
    vector<string> result = houses->readHouse({});
    return result;
}

/**
 * @return vector<string>
 */
vector<string> Admin::viewAllUser() {
    Database * database = Database::getInstance();
    MemberDatabase * members = database->getMemberDatabase();
    vector<string> result = members->readMember({});
    return result;
}

/**
 * @param username
 * @param password
 * @return bool
 */
bool Admin::compareUsernameandPassword(string username, string password) {
    std::cout << this->username << this->password << std::endl;
    return (this->username == username && this->password == password);
}