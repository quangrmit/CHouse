/**
 * Project Untitled
 */
// temporal backup



#include "CLI.h"
void printVector(vector<string> &data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }
}

using std::getline;
/**
 * CLI implementation
 */

TableGenerator *tableGenerator;
vector<string> result;
string houseHeader = "HouseID,Description,City,House Rating,Start,End,Consuming Point,Min Occupier Rating,Reviews";
string requestHeader = "Request ID,Member ID,House ID,Start,End,Status,Close";
string memberHeader = "Member ID,Full Name,Username,Password,Phone Number,HouseID,Credit,Occupier Rating,Review";
Authorization * authorize = new Authorization();
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
    bool end = false;
    int choice;
    while (true) {
        if (end) return;
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
                end = true;
                break;
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
    map<string, string> userData;
    map<string, string> houseData;
    int choice; 
    vector<string> result;
    while (true) {
        cout << "0. Exit\n"
                "1. View all house information.\n"
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
                result = guest->viewAllHouse();
                printVector(result);
                // tableGenerator->printTable("ID,Description,City", result);
                break;

            case 2:
                cin.ignore(1, '\n');
                cout << "Enter user detail: " << endl;
                cout << "Enter fullname: ";
                getline(cin, userData["fullname"]);
                cout << "Enter username: ";
                getline(cin, userData["username"]);
                cout << "Enter password: ";
                getline(cin, userData["password"]);
                cout << "Enter phone number: ";
                getline(cin, userData["phonenumber"]);

                cout << "Enter house detail: " << endl;
                cout << "Enter description: ";
                getline(cin, houseData["description"]);
                cout << "enter city: ";
                getline(cin, houseData["city"]);

                cout<< houseData["city"];
                if (authorize->registerUser(userData, houseData)) {
                    cout << "Register succesfull" << endl;
                    
                }
                else {
                    cout << "Register failed successfully" << endl;
                }
                break;

            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
    }
}

void CLI::openMemberMenu() {
    // Member *member = new Member();
    string mID, city, hID, start, end, rID;
    int consumingPoint, rating;
    string username, password;
    // Date start, end;
    int choice; 
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << endl;
    currentMember =  authorize->login(username, password);
    if (currentMember == nullptr) {
        cout << "Username or password is incorrect, please try again";
        return;
    }
    cout << "Welcome " << currentMember->getFullname() << endl;
    while (true) {

        cout << "0. Exit\n"
                "1. View my information\n"
                "2. List house available to be occupied\n"
                "3. Unlist house\n"
                "4. Search house\n"
                "5. Rate my occupier\n"
                "6. Rate my occupied house\n"
                "7. Request to occupy a new house\n"
                "8. Check out\n"
                "9. View all requests to my listed house \n"
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
                result = split(currentMember-> viewInfo(),',');
                cout << currentMember->viewInfo() << endl;
                // tableGenerator->printTable(memberHeader, result);
                break;
            
            case 2:
                cout << "Enter the start of the house:";
                getline(cin, start);
                cout << "\nEnter the end of the house:";
                getline(cin, end);
                cout << "\nEnter the consuming point: ";
                cin >> consumingPoint;
                currentMember->listhouse(Date::string_to_date( start),Date::string_to_date(end),consumingPoint);
                break;

            case 3: 
                currentMember -> unlisthouse();
                break;
            
            case 4: 
                cout << "Enter the start of your searching stay:";
                getline(cin, start);
                cout << "\nEnter the end of your searching stay:";
                getline(cin, end);
                cout << "\nEnter your wanted city:";
                getline(cin, city);

                result = currentMember -> searchHouse(Date::string_to_date(start), Date::string_to_date(end), city);
                // tableGenerator->printTable(memberHeader,result);
                break;

            case 5:
                cout << "Please enter the Member ID you want to give reviews: ";
                getline(cin, mID);
                cout << "\nEnter the rating:";
                cin >> rating;
                currentMember -> rateOccupier(mID, rating);
                break;
            
            case 6:
                cout << "Please enter the House ID you want to give reviews: ";
                getline(cin, hID);  
                cout << "\nEnter the rating: ";
                cin >> rating;
                currentMember -> rateHouse(hID, rating);

            case 7:
                cout << "Please enter the start of your stay: ";
                getline(cin, start);
                cout << "\nPlease enter the end of your stay: ";
                getline(cin, end);
                cout << "\nPlease enter the House ID of the house you want to stay: ";
                getline(cin, hID);
                currentMember->requestStaying(Date::string_to_date(start), Date::string_to_date(end), hID);
            
            case 8:
                // input checkout paramter
                // currentMember->checkout();

            case 9:
                result = currentMember->viewAllRequests();
                // tableGenerator->printTable(requestHeader,result);

            case 10: 
                cout << "Enter Request ID of the accepted request: ";
                getline(cin, rID);
                currentMember->acceptRequest(rID);

            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
    }

}

void CLI::openAdminMenu() {
    // Admin *admin = new Admin();

    int choice;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << endl;
    currentAdmin =  authorize->loginAdmin(username, password);
    if (currentMember == nullptr) {
        cout << "Username or password is incorrect, please try again";
        return;
    }
    cout << "Welcome admin" << endl;    
    while (true) {
        cout << "0. Exit\n"
                "1. View information of all users\n"
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
                result = currentAdmin->viewAllUser();
                printVector(result);
                
                // tableGenerator->printTable(memberHeader, result) ;
                break;
            case 2:
                result = currentAdmin -> viewAllHouse();
                printVector(result);
                // tableGenerator->printTable(houseHeader, result);  
                break;          
            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
    }
}

