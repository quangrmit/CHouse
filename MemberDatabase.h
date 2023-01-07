/**
 * Project Untitled
 */
#include "Member.h"
#include <map>
#include <string>
#include <vector>


using std::any;
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
    bool createMember(map<string, string> data);

    /**
     * @param string mID
     */
    Member* findMember(string mID);

    /**
     * @param data
     */
    MemberDatabase(vector<string> data);

   private:
    vector<Member*> members;
};

#endif  //_MEMBERDATABASE_H