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

TableGenerator *tableGenerator = new (std::nothrow) TableGenerator;
Database *db = Database::getInstance();
vector<string> result;
vector<string> space(10, "-");
string sp = "\n" + join(space, '-') + "\n";
string houseHeader = "HouseID,Description,City,House Rating,Start,End,Consuming Point,Min Occupier Rating,Reviews";
string requestHeader = "Request ID,Member ID,House ID,Start,End,Status,Occupier Review,Close";
string memberHeader = "Member ID,Full Name,Username,Password,Phone Number,HouseID,Credit,Occupier Rating,Reviews";
Authorization *authorize = new Authorization();
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
                "Enter your choice: ";
        cin >> choice;
        cout << sp;
        if (cin.fail()) {
            cout << "Please enter valid input \n";
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }
        switch (choice) {
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
                cout << "Phone number (10 digits and starts with 0): ";
                getline(cin, userData["phonenumber"]);

                cout << "Enter house detail: " << endl;
                cout << "Description: ";
                getline(cin, houseData["description"]);
                cout << "City: ";
                getline(cin, houseData["city"]);
                if (houseData["city"] != "Sai Gon" && houseData["city"] != "Ha Noi" && houseData["city"] != "Hue") {
                    cout << "Our services only available in Sai Gon, Ha Noi or Hue" << endl
                         << "\n";
                    break;
                }

                if (authorize->registerUser(userData, houseData)) {
                    cout << "Register succesfully!" << endl;
                } else {
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
    int consumingPoint = 0, rating;
    string username, password, cPoint;
    string minORating;
    // Date start, end;
    int choice;
    cin.ignore(1, '\n');
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    cout << endl;
    currentMember = authorize->login(username, password);
    cout << sp;
    if (currentMember == nullptr) {
        cout << "Username or password is incorrect, please try again";
        return;
    }
    cout << "Welcome " << currentMember->getFullname() << endl;
    while (true) {
        db->updateFile();
        cout << "0. Exit\n"
                "1. View my information\n"
                "2. List house \n"
                "3. Unlist house\n"
                "4. Search house\n"
                "5. View a specific house's reviews\n"
                "6. Request to occupy a new house\n"
                "7. Check out\n"
                "8. View all requests to my listed house \n"
                "9. Accept a request\n"
                "10. View unreview occupier\n"
                "11. Review occupier\n"
                "12. View all my outcoming requests\n"
                "13. Cancel an outcoming request\n"
                "14. View requester info\n"
                "Enter your choice: ";

        cin >> choice;
        cout << sp;
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
                result = {currentMember->viewInfo()};
                tableGenerator->printTable(memberHeader, result);
                break;

            case 2:
                cin.ignore(1, '\n');
                cout << "Enter the start date of the house: ";
                getline(cin, start);
                cout << "Enter the end date of the house: ";
                getline(cin, end);
                cout << "Enter the consuming point: ";
                getline(cin, cPoint);
                if (cPoint != "") consumingPoint = std::stoi(cPoint);
                cout << "\nEnter minimum occupier rating (optional): ";
                getline(cin, minORating);
                if (minORating == "") minORating = "-11";

                if (currentMember->listhouse(Date::stringToDate(start), Date::stringToDate(end), consumingPoint, std::stod(minORating))) {
                    cout << "\nList house successfully" << endl;
                } else {
                    cout << "\nList house failed" << endl;
                }
                break;

            case 3:
                currentMember->unlisthouse();
                cout << "Unlist house successfully";

                break;

            case 4:
                cin.ignore(1, '\n');
                cout << "Enter the start of your searching stay:";
                getline(cin, start);
                cout << "Enter the end of your searching stay:";
                getline(cin, end);
                cout << "Enter your wanted city:";
                getline(cin, city);

                result = currentMember->searchHouse(Date::stringToDate(start), Date::stringToDate(end), city);
                tableGenerator->printTable(houseHeader, result);
                break;

            case 5:

                cin.ignore(1, '\n');
                cout << "Please enter the House ID you want to view reviews: ";
                getline(cin, hID);
                if (currentMember->viewHouseReviews(hID) == "Invalid House ID.") {
                    cout << currentMember->viewHouseReviews(hID);
                } else {
                    result = {hID + "," + currentMember->viewHouseReviews(hID)};
                    tableGenerator->printTable("HouseID,Reviews", result);
                }
                // if (currentMember->viewHouseReviews(hID) == "Invalid House ID") {
                //     cout << "Invalid House ID\n";
                // } else {
                //     result= {hID + "," + currentMember->viewHouseReviews(hID)};
                //     tableGenerator->printTable("HouseID,Reviews", result);
                // }
                break;

            case 6:
                cin.ignore(1, '\n');
                cout << "Please enter the start of your stay: ";
                getline(cin, start);
                cout << "Please enter the end of your stay: ";
                getline(cin, end);
                cout << "Please enter the House ID of the house you want to stay: ";
                getline(cin, hID);
                int intHid;
                try {
                    intHid = std::stoi(hID);
                    hID = std::to_string(intHid);
                    if (currentMember->requestStaying(Date::stringToDate(start), Date::stringToDate(end), hID)) {
                        cout << "Request successfully" << endl;
                    } else {
                        cout << "Request failed" << endl;
                    }
                } catch (std::exception e) {
                    cout << "Request failed" << endl;
                }

                break;
            case 7:
                // input checkout paramter
                cin.ignore(1, '\n');
                cout << "Please enter point: ";
                getline(cin, point);
                if (point == "") {
                    cout << "No point provided" << endl;
                    break;
                }
                cout << "Please enter comment: ";
                getline(cin, comment);
                if (comment == "") {
                    cout << "No comment provided" << endl;
                    break;
                }
                if (currentMember->checkout(std::stod(point), comment)) {
                    cout << "Checkout successfully" << endl;
                } else {
                    cout << "You aren't occupy any house yet" << endl;
                }

                break;
            case 8:
                result = currentMember->viewAllRequests();
                tableGenerator->printTable(requestHeader, result);
                break;

            case 9:
                cin.ignore(1, '\n');
                cout << "Enter Request ID of the accepted request: ";
                getline(cin, rID);
                if (currentMember->acceptRequest(rID)) {
                    cout << "Accept successfully" << endl;
                } else {
                    cout << "Accept failed" << endl;
                }
                break;
            case 10:
                cin.ignore(1, '\n');
                result = currentMember->viewUnreview();
                tableGenerator->printTable("From Request, Unreviewed Occupier ID,House ID,Start,End,Status,Occupier Review,Close", result);
                break;
            case 11:
                cin.ignore(1, '\n');
                cout << "Please enter rID of the request: ";
                getline(cin, rID);
                cout << "Please enter mID of review occupier: ";
                getline(cin, mID);
                cout << "Please enter point: ";
                getline(cin, point);
                if (point == "") {
                    cout << "No point enter" << endl;
                    break;
                }
                try {
                    int intRid, intMid;
                    intRid = std::stoi(rID);
                    intMid = std::stoi(mID);

                    rID = std::to_string(intRid);
                    mID = std::to_string(intMid);

                    cout << "Please enter comment: ";
                    getline(cin, comment);
                    if (currentMember->reviewOccupier(rID, mID, std::stod(point), comment)) {
                        cout << "Review successfully" << endl;
                    } else {
                        cout << "Review failed" << endl;
                    }
                } catch (std::exception e) {
                    cout << "Review failed" << endl;
                }
                break;
            case 12:
                result = currentMember->viewMyRequests();
                tableGenerator->printTable(requestHeader, result);
                break;
            case 13:
                cin.ignore(1, '\n');
                cout << "Enter Request ID of the request you want to cancel: ";
                getline(cin, rID);
                currentMember->cancelRequest(rID);
                break;
            case 14:
                cin.ignore(1, '\n');
                cout << "Enter Request ID of the requester you want to view: ";
                getline(cin, rID);
                result = {currentMember->viewRequesterInfo(rID)};
                if (result[0] == "Invalid rID" || result[0] == "Request closed") {
                    cout << currentMember->viewRequesterInfo(rID);
                } else {
                    tableGenerator->printTable("Requester ID,Full Name, Username,Phone Number,HouseID,Credit, Occupier Rating,Reviews", result);
                }
                break;

            default:
                cout << "Invalid input. Please try another one! \n";
                break;
        }
        cout << sp;
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
    currentAdmin = authorize->loginAdmin(username, password);
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

                tableGenerator->printTable("Member ID,Full name,Username,Password, Phone Number,House ID,Credit,Occupier Rating,Reviews", result);
                break;
            case 2:
                result = currentAdmin->viewAllHouse();
                // printVector(result);
                tableGenerator->printTable(houseHeader, result);
                break;
            default:
                cout << "Invalid input. Please try another one! \n";
                break;
        }
        cout << sp;
    }
}
