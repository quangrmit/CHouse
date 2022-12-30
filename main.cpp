#include "Database.h"
#include "CLI.h"

// testing only 
#include <iostream>
void printVector(vector<string> &data) {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << std::endl;
    }
}
//
int main() {
    Database * data = Database::getInstance();
    // app.run()
    //delete data;
    // delete app; 

    // Test
    // MemberDatabase * members = data->getMemberDatabase();
    // HouseDatabase * houses = data->getHouseDatabase();
    // RequestDatabase * requests = data->getRequestDatabase();
    // printVector( members->readMember({}));
    // Member * dummy = members->findMember("1");
    // std::cout << dummy->toString() << std:: endl;
    // dummy->setCredit(9000);
    // map<string, any> another{{"fullName", "Man"}, {"username", "Manual"}, {"password", "123"}, {"phoneNumber", "009"}, {"hID", 5}};
    // if (members->createMember(another)) {
    //     std::cout << "Create successfully" << std::endl;
    // }
    // else {
    //     std::cout << "Your data is invalid or missing info" << std::endl;
    // }
    // map<string, any> house{{"description", "nice house"}, {"city","HCM"}};
    // if (houses->createHouse(house)) {
    //     std::cout << "Create successfully" << std::endl;
        
    // }
    // else {
    //     std::cout << "Your data is invalid or missing info" << std::endl;
    // }

    // map<string, any> request{{"status", 1}};
    // printVector(requests->readRequest(request));

    // data->updateFile();
    CLI * test = new CLI();
    test->welcome();
}