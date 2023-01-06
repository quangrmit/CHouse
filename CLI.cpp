/**
 * Project Untitled
 */


#include "CLI.h"
#include "Guest.h"
#include "Member.h"
#include "Admin.h"
#include "Database.h"


using std::getline;
/**
 * CLI implementation
 */

TableGenerator *tableGenerator;
string houseHeader = "HouseID,Description,City,House Rating,Start,End,Consuming Point,Min Occupier Rating,Reviews";
string requestHeader = "Request ID,Member ID,House ID,Start,End,Status,Close";
string memberHeader = "Member ID,Full Name,Username,Password,Phone Number,HouseID,Credit,Occupier Rating,Review";

CLI::CLI() {
    cout << "EEET2482/COSC2082 ASSIGNMENT /n"
          "VACATION HOUSE EXCHANGE APPLICATION /n/n"
          "Instructors: Mr. Linh Tran & Phong Ngo/n"
          "Group: Group Name/n"
          "s3927588, Nguyen Ngoc Khanh Linh/n";
          "s3927198, Nguyen Duc Quang/n";
          "s3927220, Nguyen Minh Nguyen/n";
          "s3927049, Mai Gia Phu/n";

    CLI::welcome();
}

void CLI::welcome() {
    int choice;
    while (true) {
        cout << "Use the app as 1.Guest 2.Member 3.Admin/n"
            "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                openGuestMenu();
                break;

            case 2:
                openMemberMenu();
                break;
            
            case 3: 
                openAdminMenu();
                break;

            default: 
                cout << "Invalid input. Please try another one! /n";
        }
    }    
}

void CLI::openGuestMenu() {
    Guest *guest = new Guest();
    int choice; 
    while (true) {
        cout << "1. View all house information./n"
                "2. Register as a member/n"
                "Enter your choice: ";

        cin >> choice;
        switch (choice) {
            case 1:                
            tableGenerator->printTable("ID,Description,City", guest->viewAllHouse());
                break;

            case 2:
                break;

            default: 
                cout << "Invalid input. Please try another one! /n";
        }
    }
}

void CLI::openMemberMenu() {
    Member *member = new Member();
    string mID, city, hID, start, end, rID;
    // Date start, end;
    int choice; 
    while (true) {
        cout << "1. View my information/n"
                "2. List house available to be occupied/n"
                "3. Unlist house/n"
                "4. Search house/n"
                "5. Rate my occupier/n"
                "6. Rate my occupied house/n"
                "7. Request to occupy a new house/n"
                "8. Check out/n"
                "9. View all requests to my listed house /n "
                "10. Accept a request/n"
                "Enter your choice: ";
    }

    cin >> choice;

    while (true) {
        switch (choice) {
            case 1:
                tableGenerator->printTable(memberHeader,split(member-> viewInfo(),','));
                break;
            
            case 2:
                member->listhouse();
                break;

            case 3: 
                member -> unlisthouse();
                break;
            
            case 4: 
                cout << "Enter the start of your searching stay:";
                getline(cin, start);
                cout << "\nEnter the end of your searching stay:";
                getline(cin, end);
                tableGenerator->printTable(memberHeader,
                member -> searchHouse(Date::string_to_date(start), Date::string_to_date(end), city));
                break;

            case 5:
                cout << "Please enter the Member ID you want to give reviews: ";
                getline(cin, mID);
                member -> rateOccupier(mID);
                break;
            
            case 6:
                cout << "Please enter the House ID you want to give reviews: ";
                getline(cin, hID);  
                member -> rateHouse(hID);

            case 7:
                cout << "Please enter the start of your stay: ";
                getline(cin, start);
                cout << "Please enter the end of your stay: ";
                getline(cin, end);
                cout << "Please enter the House ID of the house you want to stay: ";
                getline(cin, hID);
                member->requestStaying(Date::string_to_date(start), Date::string_to_date(end), hID);
            
            case 8:
                member->checkout();

            case 9:
                tableGenerator->printTable(requestHeader, member->viewAllRequests());

            case 10: 
                cout << "Enter Request ID of the accepted request: ";
                getline(cin, rID);
                member->acceptRequest(rID);

            default: 
                cout << "Invalid input. Please try another one! /n";
        }
    }

}

void CLI::openAdminMenu() {
    Admin *admin = new Admin();

    int choice;
    while (true) {
        cout << "1. View information of all users/n"
                "2. View information of all houses/n";
    }
    cin >> choice;

    while (true) {
        switch (choice) {
            case 1:
                tableGenerator->printTable(memberHeader, admin->viewAllUser()) ;
            case 2:
                tableGenerator->printTable(houseHeader,admin -> viewAllHouse());            
            default: 
                cout << "Invalid input. Please try another one! /n";
        }
    }
}

