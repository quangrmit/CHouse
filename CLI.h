/**
 * Project Untitled
 */


#ifndef _CLI_H
#define _CLI_H
#include "Member.h"
#include "Admin.h"
#include "Date.h"
#include "Guest.h"
#include "Admin.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;


class CLI {
public: 
    
CLI();
    
void welcome();
    
void openGuestMenu();
    
void openMemberMenu();
    
void openAdminMenu();
private: 
    Member * currentMember;
    Admin * currentAdmin;
};

#endif //_CLI_H