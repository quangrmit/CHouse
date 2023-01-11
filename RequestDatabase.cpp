/**
 * Project Untitled
 */

#include "RequestDatabase.h"

#include <iostream>
/**
 * RequestDatabase implementation
 */

/**
 * @param data
 * @return vector<Request*>
 */
vector<Request*> RequestDatabase::readRequestPointers(map<string, string> data) {
    vector<Request*> result;
    string emptyMark = "#";
    // vector<string> filters = {"start", "end", "hID", "mID", "rID", "status"};
    // Check if data is empty
    Date start;
    Date end;
    string hID;
    string mID;
    string rID;
    int status;
    bool close;
    if (data.empty()) {
        for (int i = 0; i < requests.size(); i++) {
            result.push_back(requests[i]);
        }
    } else {
        if (data.count("start") == 0) {
            data["start"] = emptyMark;
        } else {
            start = Date::stringToDate(data["start"]);
        }
        if (data.count("end") == 0) {
            data["end"] = emptyMark;
        } else {
            end = Date::stringToDate(data["end"]);
        }
        if (data.count("hID") == 0) {
            data["hID"] = emptyMark;
        } else {
            hID = data["hID"];
        }
        if (data.count("mID") == 0) {
            data["mID"] = emptyMark;
        } else {
            mID = data["mID"];
        }
        if (data.count("rID") == 0) {
            data["rID"] = emptyMark;
        } else {
            rID = data["rID"];
        }
        if (data.count("status") == 0) {
            data["status"] = emptyMark;
        } else {
            status = std::stoi(data["status"]);
        }
        if (data.count("close") == 0) {
            data["close"] = emptyMark;
        } else {
            close = (data["close"] == "false") ? false : true;
        }
        for (Request* request : requests) {
            if ((start >= request->getStart() || data["start"] == emptyMark) &&
                (end <= request->getAnEnd() || data["end"] == emptyMark) &&
                (hID == request->getHid() || data["hID"] == emptyMark) &&
                (mID == request->getMid() || data["mID"] == emptyMark) &&
                (rID == request->getRid() || data["rID"] == emptyMark) &&
                (close == request->isClose() || data["close"] == emptyMark) &&
                (request->getStatus() == status || data["status"] == emptyMark)) {
                result.push_back(request);
            }
        }
    }
    return result;
}

/**
 * @param data
 * @return vector<string>
 */
vector<string> RequestDatabase::readRequest(map<string, string> data) {
    vector<string> result;
    vector<Request*> requestPointers = this->readRequestPointers(data);
    for (Request* request : requestPointers) {
        result.push_back(request->toString());
    }
    return result;
}

/**
 * @param request
 * @return vector<Request*>
 */
vector<Request*> RequestDatabase::findOverlapRequests(Request* request) {
    vector<Request*> result;
    Date startBase = request->getStart();
    Date endBase = request->getAnEnd();
    for (Request* other : requests) {
        if (!(startBase > other->getAnEnd() || endBase < other->getStart()) && other->getHid() == request->getHid()) {
            result.push_back(other);
        }
    }
    return result;
}

/**
 * @param data
 * @return bool
 */
bool RequestDatabase::createRequest(map<string, string> data) {
    try {
        string hID = data["hID"];
        string mID = data["mID"];
        string rID = std::to_string(requests.size() + 1);
        Date start = Date::stringToDate(data["start"]);
        Date end = Date::stringToDate(data["end"]);

        Request* request = new Request(rID, mID, hID, start, end);
        requests.push_back(request);
        return true;
    } catch (std::bad_alloc) {
        return false;
    }
}

/**
 * @param rID
 * @return Request *
 */
Request* RequestDatabase::findRequest(string rID) {
    for (int i = 0; i < requests.size(); i++) {
        if (requests[i]->getRid() == rID) {
            return requests[i];
        }
    }
    return nullptr;
}

/**
 * @param data
 */
RequestDatabase::RequestDatabase(vector<string> data) {
    Request* request;
    for (int i = 0; i < data.size(); i++) {
        request = new Request(data[i]);
        requests.push_back(request);
    }
}