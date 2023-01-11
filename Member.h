/**
 * Project Untitled
 */
#include <string>
#include <vector>

#include "Database.h"
#include "Date.h"
using std::cout;
using std::endl;

using std::string;
using std::vector;

#ifndef _MEMBER_H
#define _MEMBER_H

class Member {
   public:
    Member();
    Member(string data);

    Member(const string &mId, const string &fullname, const string &username, const string &password,
           const string &phonenumber, const string &hId, int credit = 500, double occupierRating = -11,
           const vector<std::vector<string>> &review = {});

    int getCredit() const;

    void setCredit(int credit);

    const string &getHid() const;

    void setHid(const string &hId);

    double getOccupierRating() const;

    void setOccupierRating(double occupierRating);

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

    const vector<std::vector<string>> &getReview() const;

    void setReview(const vector<std::vector<string>> &review);

    string viewInfo();

    bool listhouse(Date start, Date end, int consumingPoint, double minOccupierRating = -11);

    bool unlisthouse();

    vector<string> searchHouse(Date start, Date end, string city);

    void rateOccupier(string mID, double rating);

    void rateHouse(string hID, double rating);

    vector<string> viewMyRequests();

    bool requestStaying(Date start, Date end, string hID);

    void cancelRequest(string rID);

    bool checkout(double point, string comment);

    vector<string> viewUnreview();

    string viewRequestMemberInfo(string rID);

    void addReview(vector<string> review);

    bool reviewOccupier(string rID, string mID, double rating, string comment);

    vector<string> viewAllRequests();

    bool acceptRequest(string rID);

    bool compareUsernameandPassword(string username, string password);

    string toString();
    string censoredToString();

   private:
    string mID;
    string fullname;
    string username;
    string password;
    string phonenumber;
    string hID;
    int credit;
    double occupierRating;
    std::vector<std::vector<string>> review;
};

#endif  //_MEMBER_H