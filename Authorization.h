/**
 * Project Untitled
 */

#ifndef _AUTHORIZATION_H
#define _AUTHORIZATION_H

#include <map>
#include <string>
#include <vector>

#include "Admin.h"
#include "Database.h"
#include "Date.h"
#include "utils.h"
using std::string;

using std::vector;

using std::map;
using std::string;

class Authorization {
   public:
    Authorization();

    /**
     * @param username
     * @param password
     */
    Member* login(std::string username, std::string password);

    /**
     * @param data
     *
     */

    bool registerUser(map<string, string> userData, map<string, string> houseData);

    /**
     * @param username
     * @param password
     */
    Admin* loginAdmin(string username, string password);
};

#endif  //_AUTHORIZATION_H