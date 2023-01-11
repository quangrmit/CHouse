/**
 * Project Untitled
 */

#include "House.h"

/**
 * House implementation
 */

/**
 * @return string
 */
string House::toString() {
    string cP, minORating, startDate, endDate, hRating;
    (consumingPoint == -1) ? cP = "" : cP = std::to_string(consumingPoint);
    (minOccupierRating == -11) ? minORating = "" : minORating = std::to_string(minOccupierRating);
    (houseRating == -11) ? hRating = "" : hRating = std::to_string(houseRating);
    (start.isEmpty()) ? startDate = "" : startDate = Date::dateToString(&start);
    (end.isEmpty()) ? endDate = "" : endDate = Date::dateToString(&end);

    return this->hID + "," + this->description + "," + this->city + "," + hRating + "," + startDate + "," + endDate + "," +
           cP + "," + minORating + "," + reviewToString();
}

/**
 * @param data
 */
House::House(string data) {
    std::vector<string> dataList = split(data, ',');

    std::vector<std::vector<string>> reviews;
    if (dataList.size() == 9) {
        std::vector<string> reviewList = split(dataList[8], ';');
        for (string review : reviewList) {
            reviews.push_back(split(review, '_'));
        }
    }

    Date startDate, endDate;
    if (dataList[4].empty()) {
        startDate.setEmpty();
        endDate.setEmpty();
    } else {
        std::vector<string> start = split(dataList[4], '/');
        startDate = Date(std::stoi(start[0]), std::stoi(start[1]), std::stoi(start[2]));

        std::vector<string> end = split(dataList[5], '/');
        endDate = Date(std::stoi(end[0]), std::stoi(end[1]), std::stoi(end[2]));
    }

    int cP;
    double minORating, hRating;
    (dataList[6] == "") ? cP = -1 : cP = std::stoi(dataList[6]);
    (dataList[7] == "") ? minORating = -11 : minORating = std::stod(dataList[7]);
    (dataList[3] == "") ? hRating = -11 : hRating = std::stod(dataList[3]);
    this->hID = dataList[0];
    this->description = dataList[1];
    this->city = dataList[2];
    this->houseRating = hRating;
    this->start = startDate;
    this->end = endDate;
    this->consumingPoint = cP;
    this->minOccupierRating = minORating;
    this->reviews = reviews;

    // House(std::stoi(dataList[0]), dataList[1], dataList[2], std::stoi(dataList[3]), startDate, endDate, cP, minORating, reviews);
}

House::House(string hId, const string &description, const string &city, double houseRating,
             const Date &start, const Date &anEnd, int consumingPoint, double minOccupierRating,
             const vector<vector<string>> &reviews) : hID(hId), houseRating(houseRating), description(description), city(city), start(start), end(anEnd), consumingPoint(consumingPoint), minOccupierRating(minOccupierRating), reviews(reviews){};
string House::reviewToString() {
    if (this->reviews.size() == 0) {
        return "";
    }
    vector<string> reviews;
    for (int i = 0; i < this->reviews.size(); i++) {
        reviews.push_back(join(this->reviews[i], '_'));
    }
    return join(reviews, ';');
}

void House::addReview(vector<string> review) {
    this->reviews.push_back(review);
}

double House::getHouseRating() const {
    return houseRating;
}

void House::setHouseRating(int houseRating) {
    House::houseRating = houseRating;
}

const string &House::getDescription() const {
    return description;
}

void House::setDescription(const string &description) {
    House::description = description;
}

string House::getID() {
    return this->hID;
}
string House::getCity() {
    return this->city;
}

Date House::getStartDate() {
    return this->start;
}
Date House::getEndDate() {
    return this->end;
}

int House::getConsumingPoints() {
    return this->consumingPoint;
}
double House::getMinOccupierRating() {
    return this->minOccupierRating;
}
vector<vector<string>> House::getReviews() {
    return this->reviews;
}

void House::setID(int ID) {
    this->hID = ID;
}
void House::setCity(string city) {
    this->city = city;
}
void House::setStartDate(Date date) {
    this->start = date;
}
void House::setEndDate(Date date) {
    this->end = end;
}

void House::setConsumingPoint(int consumingPoints) {
    this->consumingPoint = consumingPoints;
}
void House::setMinOccupierRating(int rating) {
    this->minOccupierRating = rating;
}
void House::setReviews(vector<vector<string>> reviews) {
    this->reviews = reviews;
}
