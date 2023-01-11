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

TableGenerator *tableGenerator = new(std::nothrow) TableGenerator;
vector<string> result;
vector<string> space (10,"-");
string sp = "\n" + join(space,'-') + "\n";
string houseHeader = "HouseID,Description,City,House Rating,Start,End,Consuming Point,Min Occupier Rating,Reviews";
string requestHeader = "Request ID,Member ID,House ID,Start,End,Status,Occupier Review,Close";
string memberHeader = "Member ID,Full Name,Username,Password,Phone Number,HouseID,Credit,Occupier Rating,Review";
Authorization * authorize = new Authorization();
CLI::CLI() {
    cout << "\n\nEEET2482/COSC2082 ASSIGNMENT \n"
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
        cout << "\nUse the app as:\n 0.Exit \n 1.Guest \n 2.Member \n 3.Admin\n"
            "Enter your choice: " ;
        cin >> choice;
        cout << sp ;
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
                cout << "This is your menu \n";
                openGuestMenu();
                break;

            case 2:
                cout << "This is your menu \n";
                openMemberMenu();
                break;
            
            case 3: 
                cout << "This is your menu \n";
                openAdminMenu();
                break;

            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
        cout << sp;
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
        // cout << sp ;
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
                // printVector(result);
                tableGenerator->printTable("ID,Description,City,House Rating", result);
                break;

            case 2:
                cin.ignore(1, '\n');
                cout << "Enter user detail: " << endl;
                cout << "Fullname: ";
                getline(cin, userData["fullname"]);
                cout << "Username: ";
                getline(cin, userData["username"]);
                cout << "Password: ";
                getline(cin, userData["password"]);
                cout << "Phone number: ";
                getline(cin, userData["phonenumber"]);
                
                cout << "Enter house detail: " << endl;
                cout << "Description: ";
                getline(cin, houseData["description"]);
                cout << "City: ";
                getline(cin, houseData["city"]);
                if (houseData["city"] != "Sai Gon" && houseData["city"] != "Ha Noi" && houseData["city"] != "Hue") {
                    cout << "Our services only available in Sai Gon, Ha Noi or Hue" << endl << "\n";
                    break;
                }
                
                if (authorize->registerUser(userData, houseData)) {
                    cout << "Register succesfully!" << endl;   
                }
                else {
                    cout << "Register failed!" << endl;
                }
                break;

            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
        cout << "\n\n";
    }
}

void CLI::openMemberMenu() {
    // Member *member = new Member();
    string mID, city, hID, start, end, rID, comment, point;
    int consumingPoint, rating;
    string username, password;
    double minORating = -11;
    // Date start, end;
    int choice; 
    cin.ignore(1, '\n');
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    cout << endl;
    currentMember =  authorize->login(username, password);
    cout << sp ;
    if (currentMember == nullptr) {
        cout << "Username or password is incorrect, please try again";
        return;
    }
    cout << "Welcome " << currentMember->getFullname() << endl;
    while (true) {

        cout << "0. Exit\n"
                "1. View my information\n"
                "2. List house \n"
                "3. Unlist house\n"
                "4. Search house\n"
                "5. View a specific house's reviews\n"
                "6. Rate my occupier\n"
                "7. Rate my occupied house\n"
                "8. Request to occupy a new house\n"
                "9. Check out\n"
                "10. View all requests to my listed house \n"
                "11. Accept a request\n"
                "12. View unreview occupier\n" 
                "13. Review occupier\n"
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
                result= {currentMember->viewInfo()};
                // cout << currentMember->viewInfo() << endl;
                // for (int i =0; i < result.size(); i++) {
                //     cout << result[i] << "\n";
                // }
                tableGenerator->printTable(memberHeader, result);
                break;
            
            case 2:
                cin.ignore(1, '\n');
                cout << "Enter the start of the house:";
                getline(cin, start);
                cout << "\nEnter the end of the house:";
                getline(cin, end);
                cout << "\nEnter the consuming point: ";
                cin >> consumingPoint;
                cout << "\nEnter minimum occupier rating (optional): ";
                cin >> minORating;

                if (currentMember->listhouse(Date::string_to_date( start),Date::string_to_date(end),consumingPoint, minORating)) {
                    cout << "\nList house successfully" << endl;
                }
                else {
                    cout << "\n List house failed" << endl;
                }
                break;

            case 3: 
                currentMember -> unlisthouse();
                break;
            
            case 4: 
                cin.ignore(1, '\n');
                cout << "Enter the start of your searching stay:";
                getline(cin, start);
                cout << "Enter the end of your searching stay:";
                getline(cin, end);
                cout << "Enter your wanted city:";
                getline(cin, city);

                result = currentMember -> searchHouse(Date::string_to_date(start), Date::string_to_date(end), city);
                tableGenerator->printTable(houseHeader,result);
                break;

            case 5: 

                cin.ignore(1, '\n');
                cout << "Please enter the House ID you want to view reviews: ";
                getline(cin, hID);                
                if (currentMember->viewHouseReviews(hID) == "Invalid House ID") {
                    cout << currentMember->viewHouseReviews(hID);
                } else {
                    result.push_back(hID + "," + currentMember ->viewHouseReviews(hID));
                    tableGenerator->printTable("HouseID,Reviews", result);
                }
                break;

            case 6:
                cin.ignore(1, '\n');
                cout << "Please enter the Member ID you want to give reviews: ";
                getline(cin, mID);
                cout << "\nEnter the rating:";
                cin >> rating;
                currentMember -> rateOccupier(mID, rating);
                break;
            
            case 7:
                cin.ignore(1, '\n');
                cout << "Please enter the House ID you want to give reviews: ";
                getline(cin, hID);  
                cout << "\nEnter the rating: ";
                cin >> rating;
                currentMember -> rateHouse(hID, rating);
                break;
            case 8:
                cin.ignore(1, '\n');
                cout << "Please enter the start of your stay: ";
                getline(cin, start);
                cout << "Please enter the end of your stay: ";
                getline(cin, end);
                cout << "Please enter the House ID of the house you want to stay: ";
                getline(cin, hID);
                if (currentMember->requestStaying(Date::string_to_date(start), Date::string_to_date(end), hID)) {
                    cout << "Request successfully" << endl;
                }
                else {
                    cout << "Request failed" << endl;
                }
                break;
            case 9:
                // input checkout paramter
                cin.ignore(1, '\n');
                cout << "Please enter point: ";
                getline(cin, point);
                cout << "Please enter comment: ";
                getline(cin, comment);
                if (currentMember->checkout(std::stod(point), comment)) {
                    cout << "Checkout successfully" << endl;
                }
                else {
                    cout << "You aren't occupy any house yet" << endl;
                }
                
                break;
            case 10:
                result = currentMember->viewAllRequests();
                tableGenerator->printTable(requestHeader,result);
                break;

            case 11: 
                cin.ignore(1, '\n');
                cout << "Enter Request ID of the accepted request: ";
                getline(cin, rID);
                if (currentMember->acceptRequest(rID)) {
                    cout << "Accept successfully" << endl;
                }else {
                    cout << "Accept failed" << endl;
                }
                break;
            case 12:
                cin.ignore(1, '\n');
                result = currentMember->viewUnreview();
                printVector(result);
                break;
            case 13:
                cin.ignore(1, '\n');
                cout << "Please enter rID of the request";
                getline(cin, rID);

                cout << "Please enter mID of review occupier: ";
                getline(cin, mID);
                cout << "Please enter point: ";
                getline(cin, point);
                cout << "Please enter comment: ";
                getline(cin, comment);
                if (currentMember->reviewOccupier(rID, mID, std::stod(point), comment)) {
                    cout << "Review successfully" << endl;
                }
                else {
                    cout << "Review failed" << endl;
                }
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
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << endl;
    cout << sp;
    currentAdmin =  authorize->loginAdmin(username, password);
    if (currentMember == nullptr) {
        cout << "Username or password is incorrect, please try again";
        return;
    }
    cout << "Welcome admin" << endl;    
    while (true) {
        cout << "0. Exit\n"
                "1. View information of all users\n"
                "2. View information of all houses\n"
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
                result = currentAdmin->viewAllUser();
                // printVector(result);
                
                tableGenerator->printTable(memberHeader, result) ;
                break;
            case 2:
                result = currentAdmin -> viewAllHouse();
                // printVector(result);
                tableGenerator->printTable(houseHeader, result);  
                break;          
            default: 
                cout << "Invalid input. Please try another one! \n";
                break;
        }
    }
}

