/**
 * Project Untitled
 */

#include "MemberDatabase.h"

/**
 * MemberDatabase implementation
 */

MemberDatabase::~MemberDatabase() {
    for (int i = members.size() - 1; i >= 0; i--) {
        delete members[i];
    }
}

/**
 * @param data
 * @return vector<Member*>
 */
vector<Member*> MemberDatabase::readMemberPointers(map<string, string> data) {
    vector<Member*> result;
    string emptyMark = "#";

    string mID;
    string hID;
    int credit;
    double occupierRating;
    string username;
    string phonenumber;
    // Check if data is empty

    if (data.empty()) {
        for (int i = 0; i < members.size(); i++) {
            result.push_back(members[i]);
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
        if (data.count("mID") == 0) {
            data["mID"] = emptyMark;
        } else {
            mID = data["mID"];
        }
        for (Member* member : members) {
            if (
                (member->getHid() == hID || data["hID"] == emptyMark) &&
                (member->getCredit() == credit || data["credit"] == emptyMark) &&
                (member->getOccupierRating() == occupierRating || data["occupierRating"] == emptyMark) &&
                (member->getUsername() == username || data["username"] == emptyMark) &&
                (member->getPhonenumber() == phonenumber || data["phonenumber"] == emptyMark) &&
                (member->getMid() == mID || data["mID"] == emptyMark)

            ) {
                result.push_back(member);
            }
        }
    }
    return result;
}

/**
 * @param data
 * @return vector<string>
 */
vector<string> MemberDatabase::readMember(map<string, string> data) {
    vector<string> result;
    vector<Member*> memberPointers = this->readMemberPointers(data);
    for (Member* member : memberPointers) {
        result.push_back(member->toString());
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
        string hID = mID;
        for (int i = 0; i < members.size(); i++) {
            if (members[i]->getUsername() == username) {
                return false;
            }
        }

        Member* member = new Member(mID, fullname, username, password, phonenumber, hID);
        members.push_back(member);

    } catch (std::bad_alloc) {
        return false;
    }
    std::cout << members.size() << std::endl;
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
    Member* member;
    for (int i = 0; i < data.size(); i++) {
        // Member member = Member(data[i]);

        member = new Member(data[i]);
        members.push_back(member);
    }
}