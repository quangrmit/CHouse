/**
 * Project Untitled
 */


#ifndef _REQUEST_H
#define _REQUEST_H

#include "string"
#include "vector"
#include "Date.h"
using std::string;
using std::vector;


class Request {
public: 
    string rID;
    
string toString();

Request(string data);

    const string &getMid() const;

    void setMid(const string &mId);

    const string &getHid() const;

    void setHid(const string &hId);

    const Date &getStart() const;

    void setStart(const Date &start);

    const Date &getAnEnd() const;

    void setAnEnd(const Date &anEnd);

    int getStatus() const;

    void setStatus(int status);

    bool isClose() const;

    void setClose(bool close);

private:
    string mID;
    string hID;
    Date start;
    Date end;
    int status;
    bool close;
};

#endif //_REQUEST_H