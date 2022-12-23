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
    std::vector<string> dataList = split(data,',');
    std::vector<string> reviewList = split(dataList[8],';');
    std::vector<std::vector<string>> reviews;

    std::vector<string> start = split(dataList[4],'/');
    Date startDate = Date(std::stoi(start[0]), std::stoi(start[1]), std::stoi(start[2]));

    std::vector<string> end = split(dataList[5],'/');
    Date endDate = Date(std::stoi(end[0]), std::stoi(end[1]), std::stoi(end[2]));

    for(string review : reviewList) {
        reviews.push_back(split(review,'_'));
    }

    House(std::stoi(dataList[0]),std::stoi(dataList[1]),dataList[2],dataList[3],startDate,endDate,std::stoi(dataList[6]), std::stoi(dataList[7]),reviews);

}

House::House(int hId, int houseRating, const string &description, const string &city,
             const Date &start, const Date &anEnd, int consumingPoint, int minOccupierRating,
             const vector<vector<string>> &reviews) : hID(hId), houseRating(houseRating),
                                                      description(description), city(city), start(start), end(anEnd),
                                                      consumingPoint(consumingPoint),
                                                      minOccupierRating(minOccupierRating), reviews(reviews) {}
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
