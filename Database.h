/**
 * Project Untitled
 */

#ifndef _DATABASE_H
#define _DATABASE_H
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Admin.h"
#include "HouseDatabase.h"
#include "MemberDatabase.h"
#include "RequestDatabase.h"
#include "utils.h"

#define FILENAME "Data.txt"

using std::string;
using std::vector;
class Database {
   public:
    Database(Database &another) = delete;
    void operator=(Database &another) = delete;
    void loadFile();

    void updateFile();

    static Database *getInstance();

    HouseDatabase *getHouseDatabase();

    MemberDatabase *getMemberDatabase();

    RequestDatabase *getRequestDatabase();
    Admin *getAdmin();

    ~Database();

   private:
    static Database *single;
    static MemberDatabase *memberDatabase;
    static HouseDatabase *houseDatabase;
    static RequestDatabase *requestDatabase;
    static Admin *admin;
    static string header1, header2, header3;

    Database();
};

#endif  //_DATABASE_H