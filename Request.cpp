/**
 * Project Untitled
 */

#include "Request.h"

#include "Date.h"
#include "string"
#include "utils.h"
#include "vector"

using std::string;
using std::vector;

string Request::toString() {
    string closeString, reviewString;
    (close == true) ? closeString = "true" : closeString = "false";
    (oReview == true) ? reviewString = "true" : reviewString = "false";

    return rID + "," + mID + "," + hID + "," + Date::dateToString(&start) + "," + Date::dateToString(&end) + "," + std::to_string(status) + "," + reviewString + "," + closeString;
}

Request::Request(string data) {
    std::vector<string> dataList = split(data, ',');

    std::vector<string> start = split(dataList[3], '/');
    Date startDate = Date(std::stoi(start[0]), std::stoi(start[1]), std::stoi(start[2]));

    std::vector<string> end = split(dataList[4], '/');
    Date endDate = Date(std::stoi(end[0]), std::stoi(end[1]), std::stoi(end[2]));

    bool complete;
    (dataList[7] == "true") ? complete = true : complete = false;

    bool review;
    (dataList[6] == "true") ? complete = true : complete = false;
    this->rID = dataList[0];
    this->mID = dataList[1];
    this->hID = dataList[2];
    this->start = startDate;
    this->end = endDate;
    this->status = std::stoi(dataList[5]);
    this->close = complete;

    //  Request(dataList[0],dataList[1],dataList[2],startDate,endDate, std::stoi(dataList[5]),complete);
}

Request::Request(const string &rId, const string &mId, const string &hId, const Date &start, const Date &anEnd,
                 int status, bool oReview, bool close) : rID(rId), mID(mId), hID(hId), start(start), end(anEnd), status(status), oReview(oReview), close(close) {}

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

const string &Request::getRid() const {
    return rID;
}

void Request::setRid(const string &rId) {
    rID = rId;
}
