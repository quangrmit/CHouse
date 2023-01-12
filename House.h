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
    House(string hId, const string &description, const string &city, double houseRating = -11,
          const Date &start = Date(), const Date &anEnd = Date(), int consumingPoint = -1, double minOccupierRating = -11,
          const vector<vector<string>> &reviews = {});
//     string getHid() const;

    void setHid(const string &hId);

    double getHouseRating() const;

    void setHouseRating(double houseRating);

    const string &getLocation() const;

    void setLocation(const string &location);

    const string &getDescription() const;

    void setDescription(const string &description);

    string getID();
    string getCity();
    Date getStartDate();
    Date getEndDate();
    int getConsumingPoints();
    double getMinOccupierRating();
    vector<vector<string>> getReviews();

    string reviewToString();
    void addReview(vector<string> review);

    void setID(int ID);
    void setCity(string city);
    void setStartDate(Date date);
    void setEndDate(Date date);
    void setConsumingPoint(int consumingPoints);
    void setMinOccupierRating(double rating);
    void setReviews(vector<vector<string>> reviews);

   private:
    string hID;
    double houseRating;
    string description;
    string city;
    Date start;
    Date end;
    int consumingPoint;
    double minOccupierRating;
    vector<vector<string>> reviews;
};

#endif  //_HOUSE_H
