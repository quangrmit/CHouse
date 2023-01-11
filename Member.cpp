/**
 * Project Untitled
 */

#include "Member.h"

#include <iostream>

#include "utils.h"

Member::Member() {}

Member::Member(string data) {
    std::vector<string> dataList = split(data, ',');

    std::vector<std::vector<string>> reviews;

    if (dataList.size() == 9) {
        std::vector<string> reviewList = split(dataList[8], ';');

        for (string review : reviewList) {
            reviews.push_back(split(review, '_'));
        }
    }
    double oRating;
    (dataList[7] == "") ? oRating = -11 : oRating = std::stod(dataList[7]);
    this->mID = dataList[0];
    this->fullname = dataList[1];
    this->username = dataList[2];
    this->password = dataList[3];
    this->phonenumber = dataList[4];
    this->hID = dataList[5];
    this->credit = std::stoi(dataList[6]);
    this->occupierRating = oRating;
    this->review = reviews;
}

Member::Member(const string &mId, const string &fullname, const string &username, const string &password,
               const string &phonenumber, const string &hId, int credit, double occupierRating,
               const vector<vector<string>> &review) : mID(mId), fullname(fullname), username(username), password(password), phonenumber(phonenumber), hID(hId), credit(credit), occupierRating(occupierRating), review(review) {}

string Member::toString() {
    std::vector<string> reviewVec;
    string reviewString = "", oRating = "";
    (occupierRating == -11) ? oRating = "" : oRating = std::to_string(occupierRating);
    if (review.size() != 0) {
        for (std::vector<string> element : review) {
            reviewVec.push_back(join(element, '_'));
        }
        reviewString = join(reviewVec, ';');
    }
    return mID + "," + fullname + "," + username + "," + password + "," + phonenumber + "," + hID + "," + std::to_string(credit) + "," +
           oRating + "," + reviewString;
}
string Member::censoredToString() {
    std::vector<string> reviewVec;
    string reviewString = "", oRating = "";
    (occupierRating == -11) ? oRating = "" : oRating = std::to_string(occupierRating);
    if (review.size() != 0) {
        for (std::vector<string> element : review) {
            reviewVec.push_back(join(element, '_'));
        }
        reviewString = join(reviewVec, ';');
    }
    return mID + "," + fullname + "," + username + "," + phonenumber + "," + hID + "," + std::to_string(credit) + "," +
           oRating + "," + reviewString;
}

string Member::viewInfo() {
    return this->toString();
}

bool Member::listhouse(Date start, Date end, int consumingPoint, double minOccupierRating) {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(hID);

    house->setStartDate(start);
    house->setEndDate(end);
    house->setConsumingPoint(consumingPoint);
    std::cout << minOccupierRating;
    house->setMinOccupierRating(minOccupierRating);

    return true;
}

bool Member::unlisthouse() {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(hID);

    Date empty = Date();
    empty.setEmpty();

    house->setStartDate(empty);
    house->setEndDate(empty);
    house->setConsumingPoint(-1);
    house->setMinOccupierRating(-11);

    return true;
}

vector<string> Member::searchHouse(Date start, Date end, string city) {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();

    map<string, string> filter;
    filter["start"] = Date::dateToString(&start);
    filter["end"] = Date::dateToString(&end);
    filter["city"] = city;

    int totalDays = end - start;

    vector<string> houseList = hdb->readHouse(filter);
    vector<string> results;
    for (string house : houseList) {
        vector<string> data = split(house, ',');
        if (data[4] == "") continue;
        if (std::stod(data[6]) * totalDays <= this->getCredit() && std::stod(data[7]) <= this->getOccupierRating()) {
            results.push_back(house);
        }
    };

    return results;
}

void Member::rateOccupier(string mID, double rating) {
    Database *db = Database::getInstance();
    MemberDatabase *mdb = db->getMemberDatabase();
    Member *member = mdb->findMember(mID);

    double reviews = member->getReview().size();
    double ORating = ((member->getOccupierRating() * reviews) + rating) / (reviews + 1);

    member->setOccupierRating(ORating);
}

void Member::rateHouse(string hID, double rating) {
    Database *db = Database::getInstance();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(hID);

    double reviews = house->getReviews().size();
    double HRating = (double)((house->getHouseRating() * reviews) + rating) / (double)(reviews + 1);
    house->setHouseRating(HRating);
}

bool Member::requestStaying(Date start, Date end, string hID) {
    Database *db = Database::getInstance();
    RequestDatabase *rdb = db->getRequestDatabase();
    HouseDatabase *hdb = db->getHouseDatabase();
    House *house = hdb->findHouse(hID);
    bool reqValid = true;
    // Validate start end date

    // If start < end then not valid
    if (start > end) {
        reqValid = false;
    } else if (start < house->getStartDate() || end > house->getEndDate()) {
        reqValid = false;
    }
    if (reqValid) {
        map<string, string> filter;
        filter["mID"] = mID;
        filter["hID"] = hID;
        filter["start"] = Date::dateToString(&start);
        filter["end"] = Date::dateToString(&end);
        filter["status"] = "-1";
        filter["close"] = "false";

        rdb->createRequest(filter);
    } else {
        std::cout << "Invalid request!!" << std::endl;
        return false;
    }
    return true;
}

bool Member::checkout(double rating, string comment) {
    Database *db = Database::getInstance();
    RequestDatabase *rdb = db->getRequestDatabase();
    HouseDatabase *hdb = db->getHouseDatabase();
    MemberDatabase *mdb = db->getMemberDatabase();

    map<string, string> filter;
    filter["mID"] = mID;
    filter["status"] = "1";
    filter["close"] = "false";

    vector<string> requests = rdb->readRequest(filter);
    if (requests.size() == 0) return false;
    string rID = split(requests[0], ',')[0];
    string hID = split(requests[0], ',')[2];

    House *h = hdb->findHouse(hID);
    Request *rq = rdb->findRequest(rID);
    Member *m = mdb->findMember(mID);

    map<string, string> filter2;
    filter2["hID"] = hID;

    string ownerID = split(mdb->readMember(filter2)[0], ',')[0];
    Member *owner = mdb->findMember(ownerID);

    Date start = rq->getStart();
    Date end = rq->getAnEnd();
    int totalDays = end - start;

    m->setCredit(m->getCredit() - (h->getConsumingPoints() * totalDays));
    owner->setCredit(owner->getCredit() + (h->getConsumingPoints() * totalDays));

    rq->setClose(true);

    vector<string> review = {std::to_string(rating), comment};

    this->rateHouse(hID, rating);
    h->addReview(review);
    return true;
}

vector<string> Member::viewUnreview() {
    Database *db = Database::getInstance();
    RequestDatabase *rdb = db->getRequestDatabase();

    map<string, string> filter;
    filter["hID"] = this->hID;
    filter["oReview"] = "false";
    filter["close"] = "true";

    vector<string> requests = rdb->readRequest(filter);
    vector<string> unreviewOccupier;

    for (string request : requests) {
        unreviewOccupier.push_back(split(request, ',')[1]);
        unreviewOccupier.push_back("From Request: " + request);
    }

    return unreviewOccupier;
}

void Member::addReview(vector<string> review) {
    this->review.push_back(review);
}

bool Member::reviewOccupier(string rID, string mID, double rating, string comment) {
    Database *db = Database::getInstance();
    MemberDatabase *mdb = db->getMemberDatabase();
    RequestDatabase *rdb = db->getRequestDatabase();
    Request *r = rdb->findRequest(rID);
    r->setOReview(true);

    Member *mem = mdb->findMember(mID);
    if (mem == nullptr) return false;
    vector<string> review = {std::to_string(rating), comment};

    rateOccupier(mID, rating);
    mem->addReview(review);
    return true;
}

vector<string> Member::viewAllRequests() {
    vector<string> result;
    Database *database = Database::getInstance();
    RequestDatabase *requestDatabase = database->getRequestDatabase();
    result = requestDatabase->readRequest({{"hID", this->hID}});
    return result;
}

// Method to allow member to view other members' detail if exist in request (unclosed request)
string Member::viewRequesterInfo(string rID) {
    Database *database = Database::getInstance();
    RequestDatabase *requestDatabase = database->getRequestDatabase();
    MemberDatabase *memberDatabase = database->getMemberDatabase();
    // Check if rID is valid (exists in request)
    Request *request = requestDatabase->findRequest(rID);
    if (request == nullptr) {
        std::cout << "Invalid rID" << std::endl;
        return "Invalid rID";
    } else if (request->isClose() == true) {
        std::cout << "Request has been closed" << std::endl;
        return "Request closed";
    } else {
        Member *member = memberDatabase->findMember(request->getMid());
        return member->censoredToString();
    }
}

vector<string> Member::viewMyRequests() {
    // Function to view all outcoming requests, including all statuses and closed/unclosed
    Database *database = Database::getInstance();
    RequestDatabase *requestDatabase = database->getRequestDatabase();

    vector<string> myRequests = requestDatabase->readRequest({{"mID", this->mID}});
    return myRequests;
}

bool Member::cancelRequest(string rID) {
    Database *database = Database::getInstance();
    RequestDatabase *requestDatabase = database->getRequestDatabase();
    vector<Request *> myRequests = requestDatabase->readRequestPointers({{"mID", this->mID}, {"close", "false"}});
    Request *toBeCanceled;
    bool reqValid = false;

    // Check if rID is valid (in list of myRequests)
    for (int i = 0; i < myRequests.size(); i++) {
        if (myRequests[i]->getRid() == rID) {
            reqValid = true;
            toBeCanceled = myRequests[i];
            break;
        }
    }
    if (reqValid) {
        toBeCanceled->setClose(true);
    } else {
        std::cout << "Invalid request ID" << std::endl;
        return false;
    }
    return true;
}

bool Member::acceptRequest(string rID) {
    Database *database = Database::getInstance();
    RequestDatabase *requestDatabase = database->getRequestDatabase();
    Request *request = requestDatabase->findRequest(rID);
    // Check if rID is valid (find function does not return nullptr)

    if (request == nullptr) {
        return false;
    }
    if (request->getHid() != this->getHid()) {
        return false;
    }
    if (request->isClose()) {
        return false;
    }
    // Find request and set status to accepted (1)

    // Find all other overlapping requests
    vector<Request *> overlaps = requestDatabase->findOverlapRequests(request);
    // Set overlapping requests to declined (0) and set close to true
    for (Request *overlap : overlaps) {
        overlap->setStatus(0);
        overlap->setClose(true);
    }
    request->setStatus(1);
    request->setClose(false);
    return true;
}

string Member::viewHouseReviews(string hID) {
    string reviews;
    Database *database = Database::getInstance();
    HouseDatabase *HouseDatabase = database->getHouseDatabase();
    House *house = HouseDatabase->findHouse(hID);
    if (house == nullptr) {
        cout << "Invalid House ID." << std::endl;
        return "Invalid House ID.";
    } else {
        reviews = house->reviewToString();
        return reviews;
    }
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

void Member::setOccupierRating(double occupierRating) {
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
