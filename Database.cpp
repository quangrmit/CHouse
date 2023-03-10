/**
 * Project Untitled
 */

#include "Database.h"
/**
 * Database implementation
 */
Database* Database::single = nullptr;
MemberDatabase* Database::memberDatabase = nullptr;
HouseDatabase* Database::houseDatabase = nullptr;
RequestDatabase* Database::requestDatabase = nullptr;
Admin* Database::admin = nullptr;
string Database::header1 = "";
string Database::header2 = "";
string Database::header3 = "";

void Database::loadFile() {
    std::ifstream storage;
    storage.open(FILENAME, std::ios::in);
    if (!storage.is_open()) {
        // Consider alternatives
        throw std::runtime_error("Please put the data file in the same directory as exe file\nThe data file is in Group22_Sources.zip name Data.txt");
    }

    std::getline(storage, header1);

    vector<string> users = extractData(storage);

    std::getline(storage, header2);

    vector<string> houses = extractData(storage);

    std::getline(storage, header3);

    vector<string> requests = extractData(storage);

    memberDatabase = new MemberDatabase(users);
    houseDatabase = new HouseDatabase(houses);

    requestDatabase = new RequestDatabase(requests);
    admin = new Admin();
    storage.close();
}

void Database::updateFile() {
    std::ofstream storage;
    storage.open(FILENAME, std::ios::out);
    if (!storage.is_open()) {
        throw std::runtime_error("Can't open file");
    }
    map<string, string> data = {};

    storage << header1 << "\n";
    vector<string> memberData = memberDatabase->readMember(data);
    for (int i = 0; i < memberData.size(); i++) {
        storage << memberData.at(i) << "\n";
    }
    storage << "\n";

    storage << header2 << "\n";
    vector<string> houseData = houseDatabase->readHouse(data);
    for (int i = 0; i < houseData.size(); i++) {
        storage << houseData.at(i) << "\n";
    }
    storage << "\n";

    storage << header3 << "\n";
    vector<string> requestData = requestDatabase->readRequest(data);
    for (int i = 0; i < requestData.size(); i++) {
        storage << requestData.at(i) << "\n";
    }
    storage << "\n";
    storage.close();
}

Admin* Database::getAdmin() {
    return admin;
}

Database::Database() {
    this->loadFile();
}

Database::~Database() {
    delete memberDatabase, requestDatabase, houseDatabase, admin;
}

/**
 * @return Database *
 */
Database* Database::getInstance() {
    if (single == nullptr) {
        single = new Database();
    }
    return single;
}

/**
 * @return HouseDatabase *
 */
HouseDatabase* Database::getHouseDatabase() {
    return houseDatabase;
}

/**
 * @return MemberDatabase *
 */
MemberDatabase* Database::getMemberDatabase() {
    return memberDatabase;
}

/**
 * @return RequestDatabase *
 */
RequestDatabase* Database::getRequestDatabase() {
    return requestDatabase;
}
