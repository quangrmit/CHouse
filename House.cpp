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
    return std::to_string(this->hID) + "," + this->description + "," + this->city + "," + std::to_string(this->houseRating) + "," + Date::date_to_string(&this->start) + "," + Date::date_to_string(&this->end) + "," +
           std::to_string(this->consumingPoint) + "," + std::to_string(this->minOccupierRating) + "," + reviewToString();
}

/**
 * @param data
 */
House::House(string data) {
}
string House::reviewToString() {
    vector<string> reviews;
    for (int i = 0; i < this->reviews.size(); i++) {
        reviews.push_back(join(this->reviews[i], '_'));
    }
    return join(reviews, ';');
}

int House::getHouseRating() const {
    return houseRating;
}

void House::setHouseRating(int houseRating) {
    House::houseRating = houseRating;
}

const string &House::getLocation() const {
    return location;
}

void House::setLocation(const string &location) {
    House::location = location;
}

const string &House::getDescription() const {
    return description;
}

void House::setDescription(const string &description) {
    House::description = description;
}



int House::getID() {
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
int House::getMinOccupierRating() {
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
