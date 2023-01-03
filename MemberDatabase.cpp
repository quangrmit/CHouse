/**
 * Project Untitled
 */

#include "MemberDatabase.h"

/**
 * MemberDatabase implementation
 */

/**
 * @param data
 * @return vector<string>
 */
vector<string> MemberDatabase::readMember(map<string, string> data) {
    vector<string> result;
    string emptyMark = "#";

    string hID;
    int credit;
    double occupierRating;
    string username;
    string phonenumber;
    // Check if data is empty
    if (data.empty()) {
        for (int i = 0; i < members.size(); i++) {
            result.push_back(members[i]->toString());
        }
    } else {
        if (data.count("hID") == 0) {
            data["hID"] = emptyMark;
        } else {
            hID = data["hID"];
        }
        if (data.count("credit") == 0) {
            data["credit"] = emptyMark;
        } else {
            credit = std::stoi(data["credit"]);
        }
        if (data.count("occupierRating") == 0) {
            data["occupierRating"] = emptyMark;
        } else {
            occupierRating = std::stod(data["occupierRating"]);
        }
        if (data.count("username") == 0) {
            data["username"] = emptyMark;
        } else {
            username = data["username"];
        }
        if (data.count("phonenumber") == 0) {
            data["phonenumber"] = emptyMark;
        } else {
            phonenumber = data["phonenumber"];
        }
        for (Member* member : members) {
            if (
                (member->getHid() == hID || data["hID"] == emptyMark) &&
                (member->getCredit() == credit || data["credit"] == emptyMark) &&
                (member->getOccupierRating() == occupierRating || data["occupierRating"] == emptyMark) &&
                (member->getUsername() == username || data["username"] == emptyMark) &&
                (member->getPhonenumber() == phonenumber || data["phonenumber"] == emptyMark)

            ) {
                result.push_back(member->toString());
            }
        }
    }
    return result;
}

/**
 * @param data
 * @return bool
 */
bool MemberDatabase::createMember(map<string, string> data) {
    try {
        string mID = std::to_string(members.size() + 1);
        string fullname = data["fullname"];
        string username = data["username"];
        string password = data["password"];
        string phonenumber = data["phonenumber"];
        string hID = data["hID"];

        Member* member = new Member(mID, fullname, username, password, phonenumber, hID);
        members.push_back(member);

    } catch (std::bad_alloc) {
        return false;
    }
    return true;
}

/**
 * @param string mID
 * @return Member *
 */
Member* MemberDatabase::findMember(string mID) {
    for (int i = 0; i < members.size(); i++) {
        if (members[i]->getMid() == mID) {
            return members[i];
        }
    }
    return nullptr;
}

/**
 * @param data
 */
MemberDatabase::MemberDatabase(vector<string> data) {
    for (int i = 0; i < data.size(); i++) {
        Member member = Member(data[i]);
        members.push_back(&member);
    }
}