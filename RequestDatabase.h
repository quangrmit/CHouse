/**
 * Project Untitled
 */


#ifndef _REQUESTDATABASE_H
#define _REQUESTDATABASE_H

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
void RequestDatabase(vector<string> data);
private: 
    vector<Request> requests;
};

#endif //_REQUESTDATABASE_H