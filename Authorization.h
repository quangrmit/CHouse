/**
 * Project Untitled
 */


#ifndef _AUTHORIZATION_H
#define _AUTHORIZATION_H



#include <string>
#include <vector>
#include "utils.h"
// #include <any>
#include <map>
#include "Date.h"

#include "Database.h"
#include "Admin.h"
using std::string;
 
using std::vector;
// using std::any;
using std::map;
using std::string;


class Authorization {
public: 

Authorization();
    
/**
 * @param username
 * @param password
 */
Member * login(std::string username, std::string password);
    
/**
* @param data
 * 
 */

bool registerUser(map<string, string> userData, map<string, string> houseData);
    
/**
 * @param username
 * @param password
 */
Admin * loginAdmin(string username, string password);
};

#endif //_AUTHORIZATION_H