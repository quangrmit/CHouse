/**
 * Project Untitled
 */

#ifndef _HOUSEDATABASE_H
#define _HOUSEDATABASE_H
#include <any>
#include <map>
#include <string>
#include <vector>

#include "Date.h"
#include "House.h"
#include "utils.h"

using std::any;
using std::map;
using std::string;
using std::vector;

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
    House* findHouse(string hID);

    /**
     * @param data
     */
    HouseDatabase(vector<string> data);

   private:
    vector<House*> houses;
};

#endif  //_HOUSEDATABASE_H