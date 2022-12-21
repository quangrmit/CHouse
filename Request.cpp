/**
 * Project Untitled
 */


#include "Request.h"
#include "string"
#include "vector"

using std::string;
using std::vector;



string Request::toString() {
    return "";
}

 Request::Request(string data) {

}

const string &Request::getMid() const {
    return mID;
}

void Request::setMid(const string &mId) {
    mID = mId;
}

const string &Request::getHid() const {
    return hID;
}

void Request::setHid(const string &hId) {
    hID = hId;
}

const Date &Request::getStart() const {
    return start;
}

void Request::setStart(const Date &start) {
    Request::start = start;
}

const Date &Request::getAnEnd() const {
    return end;
}

void Request::setAnEnd(const Date &anEnd) {
    end = anEnd;
}

int Request::getStatus() const {
    return status;
}

void Request::setStatus(int status) {
    Request::status = status;
}

bool Request::isClose() const {
    return close;
}

void Request::setClose(bool close) {
    Request::close = close;
}
