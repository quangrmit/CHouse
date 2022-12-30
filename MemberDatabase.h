/**
 * Project Untitled
 */


#ifndef _MEMBERDATABASE_H
#define _MEMBERDATABASE_H
#include <vector>
#include <string>
#include <map>
#include <any>
#include "Member.h"

using std::vector;
using std::string;
using std::map;
using std::any;

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
Member * findMember(string mID);
    
/**
 * @param data
 */
MemberDatabase(vector<string> data);
private: 
    vector<Member> members;
};

#endif //_MEMBERDATABASE_H