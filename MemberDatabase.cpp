/**
 * Project Untitled
 */

#include "MemberDatabase.h"
#include <iostream>
using namespace std;
/**
 * MemberDatabase implementation
 */

/**
 * @param data
 * @return vector<string>
 */
vector<string> MemberDatabase::readMember(map<string, string> data) {
    vector<string> result;
    // Check if data is empty

    if (data.empty()) {
        for (int i = 0; i < members.size(); i++) {
            result.push_back(members[i]->toString());
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
        string mID = data["mID"];
        string fullname = data["fullname"];
        string username = data["username"];
        string password = data["password"];
        string phonenumber = data["phonenumber"];
        string hID = data["hID"];
        int credit = 500;
        int occupierRating = -11;
        vector<vector<string>> review = {};
        Member* member = new Member(mID, fullname, username, password, phonenumber, hID, credit, occupierRating, review);
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
    Member * member;
    for (int i = 0; i < data.size(); i++) {
        // Member member = Member(data[i]);

        member = new Member(data[i]);
        members.push_back(member);
    }
}