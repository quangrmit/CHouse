#include "Database.h"
#include "CLI.h"
#include "utils.h"
#include "Date.h"
// testing only 
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

using namespace std;
//
int main() {
    // main code
    Database * data = Database::getInstance();
    CLI* session = new CLI();
    data->updateFile();
    delete data, session;
    // Database * data = Database::getInstance();
    // HouseDatabase* hdb = data->getHouseDatabase();
    // map<string,string> filter;
    // filter["start"] = "07/01/2023";
    // filter["end"] = "08/01/2023";
    // filter["city"] = "HCM";
    // vector<string> result = hdb->readHouse(filter);
    // cout << result.size();
}


