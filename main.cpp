#include "Database.h"
#include "CLI.h"

// testing only 
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

using namespace std;

int main() {
    // main code
    Database * data = Database::getInstance();
    CLI* session = new CLI();
    data->updateFile();
    delete data, session;
  
}


    // Database * data = Database::getInstance();
//       map<string, string> userData;
//     map<string, string> houseData;
// cout << "Enter user detail: " << endl;
//                 cout << "Enter fullname: ";
//                 getline(cin, userData["fullname"]);
//                 cout << endl;
//                 cout << "Enter username: ";
//                 getline(cin, userData["username"]);
//                 cout << endl;
//                 cout << "Enter password: ";
//                 getline(cin, userData["password"]);
//                 cout << endl;
//                 cout << "Enter phone number: ";
//                 getline(cin, userData["phonenumber"]);
//                 cout << endl;

//                 cout << "Enter house detail: " << endl;
//                 cout << "Enter description: ";
//                 getline(cin, houseData["description"]);
//                 cout << endl;
//                 cout << "enter city: ";
//                 getline(cin, houseData["city"]);

    // // Test
    // MemberDatabase * members = data->getMemberDatabase();
    // HouseDatabase * houses = data->getHouseDatabase();
    // RequestDatabase * requests = data->getRequestDatabase();

    
    // // map<string, string> memDum;
    // // memDum["mID"] = "1";
    // // map<string, string> houseDum;
    // // // houseDum["city"] = "Hue";
    // // houseDum["start"] = "14/12/2022";
    // // // houseDum["end"] = "09/02/2023";
    // // // houses->readHouse(houseDum);
    // // vector<string> result = houses->readHouse(houseDum);
    // // printVector(result);
    // Authorization * authorize = new Authorization();

    // Guest * test = new Guest();
    // vector<string> result = test->viewAllHouse();
    // printVector(result);
    // // members->createMember(memDum);

    // // data->updateFile();