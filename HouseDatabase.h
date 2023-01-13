/**
 * Project Untitled
 */

#ifndef _HOUSEDATABASE_H
#define _HOUSEDATABASE_H

#include <map>
#include <string>
#include <vector>

#include "Date.h"
#include "House.h"
#include "utils.h"

using std::map;
using std::string;
using std::vector;

class HouseDatabase {
   public:
    /**
     * @param data
     */
    vector<House*> readHousePointers(map<string, string> data);
    /**
     * @param data
     */
    vector<string> readHouse(map<string, string> data);

    /**
     * @param data
     */
    bool createHouse(map<string, string> data);

    /**
     * @param hID
     */
    House* findHouse(string hID);

    /**
     * @param data
     */
    HouseDatabase(vector<string> data);
    ~HouseDatabase();

   private:
    vector<House*> houses;
};

#endif  //_HOUSEDATABASE_H