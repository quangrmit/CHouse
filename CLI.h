/**
 * Project Untitled
 */


#ifndef _CLI_H
#define _CLI_H

class CLI {
public: 
    void Attribute1;
    
void CLI();
    
void welcome();
    
void openGuestMenu();
    
void openMemberMenu();
    
void openAdminMenu();
private: 
    Member * currentMember;
    Admin * currentAdmin;
};

#endif //_CLI_H