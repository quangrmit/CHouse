/**
 * Project Untitled
 */


#ifndef _REQUESTDATABASE_H
#define _REQUESTDATABASE_H
#include <vector>
#include <string>
#include <map>
#include <any>
#include "Request.h"

using std::vector;
using std::string;
using std::map;
using std::any;

class RequestDatabase {
public: 
    
/**
 * @param data
 */
vector<string> readRequest(map<string, any> data);
    
/**
 * @param data
 */
bool createRequest(map<string, any> data);
    
/**
 * @param rID
 */
Request * findRequest(string rID);
    
/**
 * @param data
 */
RequestDatabase(vector<string> data);
private: 
    vector<Request> requests;
};

#endif //_REQUESTDATABASE_H