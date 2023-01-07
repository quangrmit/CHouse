#include "Database.h"
#include "CLI.h"
#include "utils.h"
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
    

    // Test
    MemberDatabase * members = data->getMemberDatabase();
    HouseDatabase * houses = data->getHouseDatabase();
    RequestDatabase * requests = data->getRequestDatabase();

    
    map<string, string> memDum;
    memDum["fullname"] = "Pub";
    memDum["username"] = "uno";
    memDum["password"] = "123";
    memDum["phonenumber"] = "12390";
    map<string, string> houseDum;
    houseDum["description"] = "Heloo world";
    houseDum["city"] = "Hue";

    houses->createHouse(houseDum);
    

    // members->createMember(memDum);

    data->updateFile();
    
    


}