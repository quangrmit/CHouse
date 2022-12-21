/**
 * Project Untitled
 */


#include "Member.h"
#include "Date.h"


Member::Member(string data) {

}

string Member::viewInfo() {
    return "";
}


bool Member::listhouse() {
    return false;
}


bool Member::unlisthouse() {
    return false;
}

vector<string> Member::searchHouse(Date start, Date end, string city) {
    return null;
}

void Member::rateOccupier(string mID) {

}

void Member::rateHouse(string hID) {

}


void Member::requestStaying(Date start, Date end, string hID) {

}


bool Member::checkout() {
    return false;
}

vector<string> Member::viewAllRequests() {
    return null;
}

bool Member::acceptRequest(string rID) {
    return false;
}

bool Member::compareUsernameandPassword(string username, string password) {
    return false;
}

const string &Member::getHid() const {
    return hID;
}

void Member::setHid(const string &hId) {
    hID = hId;
}

int Member::getOccupierRating() const {
    return occupierRating;
}

void Member::setOccupierRating(int occupierRating) {
    Member::occupierRating = occupierRating;
}

const string &Member::getUsername() const {
    return username;
}

void Member::setUsername(const string &username) {
    Member::username = username;
}

const string &Member::getFullname() const {
    return fullname;
}

void Member::setFullname(const string &fullname) {
    Member::fullname = fullname;
}

const string &Member::getPhonenumber() const {
    return phonenumber;
}

void Member::setPhonenumber(const string &phonenumber) {
    Member::phonenumber = phonenumber;
}

const string &Member::getPassword() const {
    return password;
}

void Member::setPassword(const string &password) {
    Member::password = password;
}

const string &Member::getMid() const {
    return mID;
}

void Member::setMid(const string &mId) {
    mID = mId;
}
