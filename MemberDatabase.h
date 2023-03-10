/**
 * Project Untitled
 */
#include <map>
#include <string>
#include <vector>

#include "Member.h"

using std::map;
using std::string;
using std::vector;

#ifndef _MEMBERDATABASE_H
#define _MEMBERDATABASE_H

class MemberDatabase {
   public:
    /**
     * @param data
     */
    vector<string> readMember(map<string, string> data = {});
    /**
     * @param data
     */
    vector<Member*> readMemberPointers(map<string, string> data = {});

    /**
     * @param data
     */
    bool createMember(map<string, string> data);

    /**
     * @param string mID
     */
    Member* findMember(string mID);

    /**
     * @param data
     */
    MemberDatabase(vector<string> data);
    ~MemberDatabase();

   private:
    vector<Member*> members;
};

#endif  //_MEMBERDATABASE_H