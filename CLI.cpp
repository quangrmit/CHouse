/**
 * Project Untitled
 */


#include "CLI.h"


using std::getline;
/**
 * CLI implementation
 */


CLI::CLI() {
    cout << "EEET2482/COSC2082 ASSIGNMENT \n"
          "VACATION HOUSE EXCHANGE APPLICATION \n\n"
          "Instructors: Mr. Linh Tran & Phong Ngo\n"
          "Group: Group Name\n"
          "s3927588, Nguyen Ngoc Khanh Linh\n"
          "s3927198, Nguyen Duc Quang\n"
          "s3927220, Nguyen Minh Nguyen\n"
          "s3927049, Mai Gia Phu\n";

    CLI::welcome();
}

void CLI::welcome() {
    int choice;
    while (true) {
        cout << "Use the app as:\n 1.Guest \n 2.Member \n 3.Admin\n"
            "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Please enter valid input \n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        switch(choice) {
            case 0:
                cout << "Hope you have a nice day";
                exit(0);
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
                cout << "Invalid input. Please try another one! \n";
                break;
        }
    }    
}

void CLI::openGuestMenu() {
    Guest *guest = new Guest();
    int choice; 
    while (true) {
        cout << "1. View all house information.\n"
                "2. Register as a member\n"
                "Enter your choice: ";

        cin >> choice;
        if (cin.fail()) {
            cout << "Please enter valid input \n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        switch (choice) {
            case 0:
                return;

            case 1:
                guest->viewAllHouse();
                break;

            case 2:
                break;

            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
    }
}

void CLI::openMemberMenu() {
    // currentMember *currentMember = new currentMember();
    string mID, city, hID, start, end;
    // Date start, end;

    int choice; 
    
    while (true) {

        cout << "1. View my information\n"
                "2. List house available to be occupied\n"
                "3. Unlist house\n"
                "4. Search house\n"
                "5. Rate my occupier\n"
                "6. Rate my occupied house\n"
                "7. Request to occupy a new house\n"
                "8. Check out\n"
                "9. View all requests to my listed house \n "
                "10. Accept a request\n"
                "Enter your choice: ";

        cin >> choice;
        if (cin.fail()) {
            cout << "Please enter valid input \n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        switch (choice) {
            case 0:
                return;

            case 1:
                currentMember-> viewInfo();
                break;
            
            case 2:
                currentMember->listhouse();
                break;

            case 3: 
                currentMember -> unlisthouse();
                break;
            
            case 4: 
                cout << "Enter the start of your searching stay:";
                getline(cin, start);
                cout << "\nEnter the end of your searching stay:";
                getline(cin, end);
                currentMember -> searchHouse(Date::string_to_date(start), Date::string_to_date(end), city);
                break;

            case 5:
                cout << "Please enter the Member ID you want to give reviews: ";
                getline(cin, mID);
                currentMember -> rateOccupier(mID);
                break;
            
            case 6:
                cout << "Please enter the House ID you want to give reviews: ";
                getline(cin, hID);  
                currentMember -> rateHouse(hID);
                break;

            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
    }

}

void CLI::openAdminMenu() {
    // Admin *admin = new Admin();

    int choice;

    while (true) {
        cout << "1. View information of all users\n"
                "2. View information of all houses\n";
        cin >> choice;
        if (cin.fail()) {
            cout << "Please enter valid input \n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        switch (choice) {
            case 0:
                return;
            case 1:
                currentAdmin ->viewAllUser();
                break;
            case 2:
                currentAdmin -> viewAllHouse();        
                break;    
            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
    }
}

