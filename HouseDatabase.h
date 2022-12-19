/**
 * Project Untitled
 */


#ifndef _HOUSEDATABASE_H
#define _HOUSEDATABASE_H

class HouseDatabase {
public: 
    
/**
 * @param data
 */
vector<string> readHouse(map<string, any> data);
    
/**
 * @param data
 */
bool createHouse(map<string, any> data);
    
/**
 * @param hID
 */
House * findHouse(string hID);
    
/**
 * @param data
 */
void HouseDatabase(vector<string> data);
private: 
    vector<House> houses;
};

#endif //_HOUSEDATABASE_H