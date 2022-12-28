/**
 * Project Untitled
 */


#ifndef _ADMIN_H
#define _ADMIN_H
#include <string>
#include <vector>
#include "Date.h"
#include "Database.h"
#include "MemberDatabase.h"
#include "HouseDatabase.h"
using std::string;
using std::vector;

class Admin {
public: 

    Admin();

    
vector<string> viewAllUser();
    
vector<string> viewAllHouse();
    
/**
 * @param username
 * @param password
 */
bool compareUsernameandPassword(string username, string password);
private: 
    string username;
    string password;
};

#endif //_ADMIN_H