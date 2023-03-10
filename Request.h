/**
 * Project Untitled
 */

#ifndef _REQUEST_H
#define _REQUEST_H

#include "Date.h"
#include "string"
#include "vector"
using std::string;
using std::vector;

class Request {
   public:
    string toString();

    Request(string data);

    Request(const string &rId, const string &mId, const string &hId, const Date &start, const Date &anEnd, int status = -1,bool oReview =false ,
            bool close = false);

    const string &getRid() const;

    void setRid(const string &rId);

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

    void setOReview(bool oReview);

    bool getOReview();

   private:
    string rID;
    string mID;
    string hID;
    Date start;
    Date end;
    int status;
    bool oReview;
    bool close;
};

#endif  //_REQUEST_H