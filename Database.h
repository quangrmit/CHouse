/**
 * Project Untitled
 */


#ifndef _DATABASE_H
#define _DATABASE_H

class Database {
public: 
    
void loadFile();
    
void updateFile();
    
static Database * getInstance();
    
HouseDatabase * getHouseDatabase();
    
MemberDatabase * getMemberDatabase();
    
RequestDatabase * getRequestDatabase();
private: 
    static Database * single;
    static MemberDatabase * memberDatabase;
    static HouseDatabase * houseDatabase;
    static RequestDatabase * requestDatabase;
    
void Database();
};

#endif //_DATABASE_H