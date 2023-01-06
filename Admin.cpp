/**
 * Project Untitled
 */

#include "Admin.h"
#include "string"
#include "vector"
#include "HouseDatabase.h"
#include "Database.h"
#include "Member.h"
using std::string;
using std::vector;
/**
 * Admin implementation
 */



 Admin::Admin() {

}

/**
 * @return vector<string>
 */
vector<string> Admin::viewAllUser() {
    vector<string>result;
    vector<string>result;
    Database *database  = Database::getInstance();
    MemberDatabase *memberDatabase = database->getMemberDatabase();
    result = memberDatabase->readMember({});
    return result;
}

/**
 * @return vector<string>
 */
vector<string> Admin::viewAllHouse() {
    vector<string> result;
    Database *database  = Database::getInstance();
    HouseDatabase *houseDatabase = database->getHouseDatabase();
    result = houseDatabase->readHouse({});
    return result;

}

/**
 * @param username
 * @param password
 * @return bool
 */
bool Admin::compareUsernameandPassword(string username, string password) {
    return false;
}