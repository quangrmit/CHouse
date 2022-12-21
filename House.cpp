/**
 * Project Untitled
 */


#include "House.h"
#include "string"
#include "vector"
using std::string;
using std::vector;

/**
 * House implementation
 */


/**
 * @return string
 */
string House::toString() {
    return "Location: "+location+" Description: "+description+" House Rating: "+ std::to_string(houseRating);
}

/**
 * @param data
 */
 House::House(string data) {

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
