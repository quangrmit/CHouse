/**
 * Project Untitled
 */



#ifndef _MEMBER_H
#define _MEMBER_H
#include <string>
#include <vector>
#include "Date.h"
using std::vector;
using std::string;

class Member {
public: 

Member(string data);

    const string &getHid() const;

    void setHid(const string &hId);

    int getOccupierRating() const;

    void setOccupierRating(int occupierRating);

    const string &getUsername() const;

    void setUsername(const string &username);

    const string &getFullname() const;

    void setFullname(const string &fullname);

    const string &getPhonenumber() const;

    void setPhonenumber(const string &phonenumber);

    const string &getPassword() const;

    void setPassword(const string &password);

    const string &getMid() const;

    void setMid(const string &mId);

    string viewInfo();
    
bool listhouse();
    
bool unlisthouse();
    

vector<string> searchHouse(Date start, Date end, string city);

void rateOccupier(string mID);
    

void rateHouse(string hID);
    

void requestStaying(Date start, Date end, string hID);
    
bool checkout();
    
vector<string> viewAllRequests();
    

bool acceptRequest(string rID);

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