/**
 * Project Untitled
 */


#ifndef _ADMIN_H
#define _ADMIN_H

class Admin {
public: 
    
void Admin();
    
vector<string> viewAllUser();
    
vector<string> viewAllHouse();
    
/**
 * @param username
 * @param password
 */
static bool compareUsernameandPassword(string username, string password);
private: 
    string username;
    string password;
};

#endif //_ADMIN_H