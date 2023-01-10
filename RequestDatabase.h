/**
 * Project Untitled
 */

#ifndef _REQUESTDATABASE_H
#define _REQUESTDATABASE_H

#include <map>
#include <string>
#include <vector>

// #include "Date.h"
#include "Request.h"

using std::map;
using std::string;
using std::vector;

class RequestDatabase {
   public:
    /**
     * @param data
     */
    vector<Request*> readRequestPointers(map<string, string> data);

    /**
     * @param request
     */
    vector<Request*> findOverlapRequests(Request* request);

    /**
     * @param data
     */
    vector<string> readRequest(map<string, string> data);

    /**
     * @param data
     */
    bool createRequest(map<string, string> data);

    /**
     * @param rID
     */
    Request* findRequest(string rID);

    /**
     * @param data
     */
    RequestDatabase(vector<string> data);

   private:
    vector<Request*> requests;
};

#endif  //_REQUESTDATABASE_H