#include "Database.h"
#include "CLI.h"

// testing only 
#include <iostream>
#include <stdexcept>



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
    MemberDatabase * members = data->getMemberDatabase();
    HouseDatabase * houses = data->getHouseDatabase();
    RequestDatabase * requests = data->getRequestDatabase();

    
    map<string, string> memDum;
    memDum["occupierRating"] = "10";
    memDum["mID"] = "2";
    // memDum["username"] = "Linh";
    // memDum["phoneNumber"] = "1234578";
    // memDum["occupierRating"] = "10";
    vector<string> result = members->readMember(memDum);
    printVector(result);

    map<string, string> hDum;
    // reDum["mID"] = "3";
    // hDum["city"] = "Hue";
    // hDum["minRating"] = "1";
    hDum["start"] = "06/01/2023";
    // reDum["start"] = "07/01/2023";
    vector<string> result2 = houses->readHouse(hDum);
    printVector(result2);

    Member * dummy = members->findMember("1");
    dummy->setFullname("Mai Phu");

    House * hDummy = houses->findHouse("2");
    hDummy->setCity("HCM");

    Request * rDummy = requests->findRequest("3");
    rDummy->setClose(true);

    data->updateFile();

    // Member * dummy = members->findMember("1");
    // std::cout << dummy->toString() << std:: endl;
    // dummy->setCredit(9000);
    // map<string, string> another{{"fullName", "Man"}, {"username", "Manual"}, {"password", "123"}, {"phoneNumber", "009"}, {"hID", "5"}};
    
    // if (members->createMember(another)) {
    //     std::cout << "Create successfully" << std::endl;
    // }
    // else {
    //     std::cout << "Your data is invalid or missing info" << std::endl;
    // }
    // map<string, string> house{{"description", "nice house"}, {"city","HCM"}};
    // if (houses->createHouse(house)) {
    //     std::cout << "Create successfully" << std::endl;
        
    // }
    // else {
    //     std::cout << "Your data is invalid or missing info" << std::endl;
    // }

    // map<string, string> request{{"status", "1"}};
    // printVector(requests->readRequest(request));

    // data->updateFile();

}