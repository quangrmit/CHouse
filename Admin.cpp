/**
 * Project Untitled
 */

#include "Admin.h"
/**
 * Admin implementation
 */



 Admin::Admin() {

}

/**
 * @return vector<string>
 */
vector<string> Admin::viewAllUser() {
    Database * database = Database::getInstance();
    HouseDatabase * houses = database->getHouseDatabase();
    vector<string> result = houses->readHouse({});
    delete database, houses;
    return result;
}

/**
 * @return vector<string>
 */
vector<string> Admin::viewAllHouse() {
    Database * database = Database::getInstance();
    MemberDatabase * members = database->getMemberDatabase();
    vector<string> result = members->readMember({});
    delete database, members;
    return result;

}

/**
 * @param username
 * @param password
 * @return bool
 */
bool Admin::compareUsernameandPassword(string username, string password) {
    return (this->username.compare(username) && this->password.compare(password));
}