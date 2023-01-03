/**
 * Project Untitled
 */


#include "Guest.h"
#include "Database.h"
#include "HouseDatabase.h"
#include "utils.h"
/**
 * Guest implementation
 */


/**
 * @return vector<string>
 */
vector<string> Guest::viewAllHouse() {
    vector<string>result;
    Database *database  = Database::getInstance();
    HouseDatabase *houseDatabase = database->getHouseDatabase();
    map<string, string>data = {};
    
    vector<string>houseList = houseDatabase->readHouse(data);
    for (int i =0; i < houseList.size(); i++) {
        vector<string>temp = split(houseList[i], ',');
        vector<string>houseDisplay = {temp[0], temp[1], temp[2]};
        result.push_back(join(houseDisplay,','));        
    }
    return result;
}