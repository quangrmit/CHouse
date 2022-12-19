/**
 * Project Untitled
 */


#ifndef _MEMBERDATABASE_H
#define _MEMBERDATABASE_H

class MemberDatabase {
public: 
    
/**
 * @param data
 */
vector<string> readMember(map<string, any> data);
    
/**
 * @param data
 */
bool createMember(map<string, any> data);
    
/**
 * @param string mID
 */
Member * findMember(void string mID);
    
/**
 * @param data
 */
void MemberDatabase(vector<string> data);
private: 
    vector<Member> members;
};

#endif //_MEMBERDATABASE_H