/**
 * Project Untitled
 */
#include <string>
#include <vector>
#include "Date.h"
#include "Database.h"
#include "MemberDatabase.h"
#include "HouseDatabase.h"


#ifndef _ADMIN_H
#define _ADMIN_H
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