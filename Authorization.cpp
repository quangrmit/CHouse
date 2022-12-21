/**
 * Project Untitled
 */


#include "Authorization.h"
#include "Member.h"
#include "string"
#include "vector"
using std::string;
using std::vector;
/**
 * Authorization implementation
 */


/**
 * @param username
 * @param password
 * @return Member *
 */
Member * Authorization::login(string username, string password) {
    return nullptr;
}

/**
 * @param data
 * @return bool
 */
bool Authorization::registerUser(map<string, any> data) {
    return false;
}

/**
 * @param username
 * @param password
 * @return Admin *
 */
Admin * Authorization::loginAdmin(string username, string password) {
    return nullptr;
}