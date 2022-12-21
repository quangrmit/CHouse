/**
 * Project Untitled
 */


#ifndef _HOUSEDATABASE_H
#define _HOUSEDATABASE_H
#include <vector>
#include <string>
#include <map>
#include <any>
#include "House.h"

using std::vector;
using std::string;
using std::map;
using std::any;

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
HouseDatabase(vector<string> data);
private: 
    vector<House> houses;
};

#endif //_HOUSEDATABASE_H