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
    return this->toString();
}

bool Member::listhouse(Date start, Date end , int consumingPoint, int minOccupierRating) {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(std::stoi(hID));

    house->setStartDate(start);
    house->setEndDate(end);
    house->setConsumingPoint(consumingPoint);
    house->setMinOccupierRating(minOccupierRating);

    return true;
}


bool Member::unlisthouse() {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(std::stoi(hID));

    Date empty = Date();
    empty.setEmpty();

    house->setStartDate(empty);
    house->setEndDate(empty);
    house->setConsumingPoint(0);
    house->setMinOccupierRating(-11);

    return true;
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

    double reviews = member->getReview().size();
    double ORating = ((member->getOccupierRating()*reviews)+rating)/(reviews+1);

    member->setOccupierRating(ORating);

}

void Member::rateHouse(string hID,double rating) {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(std::stoi(hID));

    double reviews = house->getReviews().size();
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

bool Member::checkout(double rating,string comment) {
    Database *db = Database::getInstance();
    RequestDatabase *rdb = db->getRequestDatabase();
    HouseDatabase *hdb = db->getHouseDatabase();

    map<string,string> filter;
    filter["mID"] = mID;
    filter["status"] ="1";
    filter["close"] = "false";

    vector<string> requests = rdb->readRequest(filter);
    string rID = split(requests[0],',')[0];
    string hID = split(requests[0],',')[2];
    House *h = hdb->findHouse(std::stoi(hID));
    Request *rq = rdb->findRequest(rID);
    rq->setClose(true);

    vector<string> review ={std::to_string(rating),comment};

    h->addReview(review);
    this->rateHouse(hID,rating);

    return false;
}

vector<string> Member::viewUnreview() {
    Database *db = Database::getInstance();
    RequestDatabase *rdb = db->getRequestDatabase();

    map<string,string> filter;
    filter["hID"] = this->hID;
    filter["oReview"] = "false";
    filter["close"] = "true";

    vector<string> requests = rdb->readRequest(filter);
    vector<string> unreviewOccupier;

    for(string request : requests) {
        unreviewOccupier.push_back(split(request,',')[1]);
    }

    return unreviewOccupier;
}

void Member::addReview(vector<string> review) {
    this->review.push_back(review);
}

void Member::reviewOccupier(string mID,double rating, string comment) {
    Database *db = Database::getInstance();
    MemberDatabase *mdb = db->getMemberDatabase();
    Member *mem = mdb->findMember(mID);

    vector<string> review = {std::to_string(rating),comment};
    mem->addReview(review);
    rateOccupier(mID,rating);
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
