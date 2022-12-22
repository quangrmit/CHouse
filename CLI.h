/**
 * Project Untitled
 */


#ifndef _CLI_H
#define _CLI_H
#include "Member.h"
#include "Admin.h"

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