/**
 * Project Untitled
 */

#include <string>
#include <vector>
using std::vector;
using std::string;


#ifndef _MEMBER_H
#define _MEMBER_H

class Member {
public: 
    
/**
 * @param data
 */
Member(string data);
    
string viewInfo();
    
bool listhouse();
    
bool unlisthouse();
    
/**
 * @param start
 * @param end
 * @param city
 */
vector<string> searchHouse(Date start, Date end, string city);
    
/**
 * @param mID
 */
void rateOccupier(string mID);
    
/**
 * @param hID
 */
void rateHouse(string hID);
    
/**
 * @param start
 * @param end
 * @param hID
 */
void requestStaying(Date start, Date end, string hID);
    
bool checkout();
    
vector<string> viewAllRequests();
    
/**
 * @param rID
 */
bool acceptRequest(string rID);
    
/**
 * @param username
 * @param password
 */
bool compareUsernameandPassword(string username, string password);
private: 
    string hID;
    int occupierRating;
    string username;
    string fullname;
    string phonenumber;
    string password;
    string mID;
};

#endif //_MEMBER_H