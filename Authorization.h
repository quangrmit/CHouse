/**
 * Project Untitled
 */


#ifndef _AUTHORIZATION_H
#define _AUTHORIZATION_H

class Authorization {
public: 
    
/**
 * @param username
 * @param password
 */
Member * login(string username, string password);
    
/**
 * @param data
 */
bool register(map data);
    
/**
 * @param username
 * @param password
 */
Admin * loginAdmin(string username, string password);
};

#endif //_AUTHORIZATION_H