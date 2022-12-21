/**
 * Project Untitled
 */

#ifndef _HOUSE_H
#define _HOUSE_H

class House {
   public:
    string toString();

    /**
     * @param data
     */
    House(string data);

   private:
    int houseRating;
    string location;
    string description;
};

#endif  //_HOUSE_H