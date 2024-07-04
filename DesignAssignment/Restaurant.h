#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Location.h"
#include "Slot.h"
#include <string>
#include <vector>

class Restaurant
{
private:
    std::string name;
    Location location;
    std::string cuisine;
    double rating;
    double costForTwo;
    bool isVeg;
    std::vector<Slot> slots;

public:
    Restaurant(std::string n, Location loc, std::string cui, double r, double cft, bool veg);

    void addSlot(const std::string &time, int tables);
    std::vector<Slot> &getSlots();

    std::string getName() const;
    std::string getCity() const;
    std::string getArea() const;
    std::string getCuisine() const;
    double getRating() const;
    double getCostForTwo() const;
    bool getIsVeg() const;

    std::string serialize() const;
    static Restaurant deserialize(const std::string &data);
};

#endif // RESTAURANT_H
