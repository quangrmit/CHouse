/**
 * Project Untitled
 */

#ifndef _HOUSE_H
#define _HOUSE_H
#include "Date.h"
#include "string"
#include "utils.h"
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

    //    House(int hId, const string &description, const string &city, int houseRating,
    //           const Date &start, const Date &anEnd, int consumingPoint, int minOccupierRating,
    //           const vector<vector<string>> &reviews);
    House(int hId, const string &description, const string &city, int houseRating = -11,
          const Date &start = Date(), const Date &anEnd = Date(), int consumingPoint = 0, int minOccupierRating = 0,
          const vector<vector<string>> &reviews = {});
    const string &getHid() const;

    void setHid(const string &hId);

    int getHouseRating() const;

    void setHouseRating(int houseRating);

    const string &getLocation() const;

    void setLocation(const string &location);

    const string &getDescription() const;

    void setDescription(const string &description);

    int getID();
    string getCity();
    Date getStartDate();
    Date getEndDate();
    int getConsumingPoints();
    int getMinOccupierRating();
    vector<vector<string>> getReviews();
    string reviewToString();

    void setID(int ID);
    void setCity(string city);
    void setStartDate(Date date);
    void setEndDate(Date date);
    void setConsumingPoint(int consumingPoints);
    void setMinOccupierRating(int rating);
    void setReviews(vector<vector<string>> reviews);

   private:
    int hID;
    int houseRating;
    string description;
    string city;
    Date start;
    Date end;
    int consumingPoint;
    int minOccupierRating;
    vector<vector<string>> reviews;
};

#endif  //_HOUSE_H
