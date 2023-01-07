/**
 * Project Untitled
 */

#include "Member.h"

#include "utils.h"

Member::Member(string data) {
    std::vector<string> dataList = split(data, ',');
    std::vector<string> reviewList = split(dataList[8], ';');
    std::vector<std::vector<string>> reviews;

    for (string review : reviewList) {
        reviews.push_back(split(review, '_'));
    }

    Member(dataList[0], dataList[1], dataList[2], dataList[3], dataList[4], dataList[5], std::stoi(dataList[6]), std::stoi(dataList[7]), reviews);
}

Member::Member(const string &mId, const string &fullname, const string &username, const string &password,
               const string &phonenumber, const string &hId, int credit, double occupierRating,
               const vector<std::vector<string>> &review) : mID(mId), fullname(fullname), username(username), password(password), phonenumber(phonenumber), hID(hId), credit(credit), occupierRating(occupierRating), review(review){};

string Member::toString() {
    std::vector<string> reviewVec;
    for (std::vector<string> element : review) {
        reviewVec.push_back(join(element, '_'));
    }
    string reviewString = join(reviewVec, ';');
    return mID + "," + fullname + "," + username + "," + password + "," + phonenumber + "," + hID + "," + std::to_string(credit) + "," +
           std::to_string(occupierRating) + "," + reviewString;
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
    vector<string> result;
    return result;
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
    vector<string> result;
    Database *database = Database::getInstance();
    RequestDatabase *requestDatabase = database->getRequestDatabase();
    result = requestDatabase->readRequest({{"hID", this->hID}});
    return result;
}

bool Member::acceptRequest(string rID) {
    Database *database = Database::getInstance();
    RequestDatabase *requestDatabase = database->getRequestDatabase();
    Request *request = requestDatabase->findRequest(rID);
    // Check if rID is valid (find function does not return nullptr)
    if (request == nullptr) {
        return false;
    } else {
        // Find request and set status to accepted (1)
        request->setStatus(1);
        // Find all other overlapping requests
        vector<Request *> overlaps = requestDatabase->findOverlapRequests(request);
        // Set overlapping requests to declined (0) and set close to true
        for (Request *overlap : overlaps) {
            overlap->setStatus(0);
            overlap->setClose(true);
        }

        return true;
    }
    return true;
}

bool Member::compareUsernameandPassword(string username, string password) {
    if (username == this->username && password == this->password) {
        return true;
    }
    return false;
}

const string &Member::getHid() const {
    return hID;
}

void Member::setHid(const string &hId) {
    hID = hId;
}

double Member::getOccupierRating() const {
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

const vector<std::vector<string>> &Member::getReview() const {
    return review;
}

void Member::setReview(const vector<std::vector<string>> &review) {
    Member::review = review;
}

int Member::getCredit() const {
    return credit;
}

void Member::setCredit(int credit) {
    Member::credit = credit;
}
