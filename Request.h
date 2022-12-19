/**
 * Project Untitled
 */


#ifndef _REQUEST_H
#define _REQUEST_H

class Request {
public: 
    string rID;
    
string toString();
    
/**
 * @param data
 */
void Request(string data);
private: 
    string mID;
    string hID;
    Date start;
    Date end;
    int status;
    bool close;
};

#endif //_REQUEST_H