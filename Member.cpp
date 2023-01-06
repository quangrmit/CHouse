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

bool Member::listhouse(Date start, Date end , int consumingPoint) {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(std::stoi(hID));

    house->setStartDate(start);
    house->setEndDate(end);
    house->setConsumingPoint(consumingPoint);



    return false;
}


bool Member::unlisthouse() {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(std::stoi(hID));

    Date empty;
    empty.setEmpty();

    house->setStartDate(empty);
    house->setEndDate(empty);
    house->setConsumingPoint(0);

    return false;
}

vector<string> Member::searchHouse(Date start, Date end, string city) {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    vector<string> result;
    map<string,string> filter;

    filter["start"] = Date::date_to_string(&start);
    filter["end"] = Date::date_to_string(&end);
    filter["city"] = city;
    result = hdb->readHouse(filter);
    return result;
}

void Member::rateOccupier(string mID,int rating) {
    Database *db = Database::getInstance();
    MemberDatabase *mdb = db->getMemberDatabase();
    Member *member = mdb->findMember(mID);

    int reviews = member->getReview().size();
    double ORating = ((member->getOccupierRating()*reviews)+rating)/(reviews+1);

    member->setOccupierRating(ORating);

}

void Member::rateHouse(string hID,int rating) {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(std::stoi(hID));

    int reviews = house->getReviews().size();
    double HRating = ((house->getHouseRating()*reviews)+rating)/(reviews+1);

    house->setHouseRating(HRating);
}

void Member::requestStaying(Date start, Date end, string hID) {
    Database *db = Database::getInstance();
    RequestDatabase *rdb = db->getRequestDatabase();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(std::stoi(hID));

    map<string,string> filter;
    filter["mID"] = mID;
    filter["hID"] = hID;
    filter["start"] = Date::date_to_string(&start);
    filter["end"] = Date::date_to_string(&end);
    filter["status"] = "-1";
    filter["close"] = "false";

    rdb->createRequest(filter);
}

bool Member::checkout() {
    return false;
}

vector<string> Member::viewAllRequests() {
    vector<string> result;
    return result;
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
