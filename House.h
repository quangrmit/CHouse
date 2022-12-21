/**
 * Project Untitled
 */

#ifndef _HOUSE_H
#define _HOUSE_H
#include "string"
#include "vector"
using std::string;
using std::vector;

class House {
   public:
    string toString();

    /**
     * @param data
     */
    House(string data);

    int getHouseRating() const;

    void setHouseRating(int houseRating);

    const string &getLocation() const;

    void setLocation(const string &location);

    const string &getDescription() const;

    void setDescription(const string &description);

   private:
    int houseRating;
    string location;
    string description;
};

#endif  //_HOUSE_H