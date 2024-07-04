#include "Restaurant.h"
#include <sstream>

Restaurant::Restaurant(std::string n, Location loc, std::string cui, double r, double cft, bool veg)
    : name(n), location(loc), cuisine(cui), rating(r), costForTwo(cft), isVeg(veg) {}

void Restaurant::addSlot(const std::string &time, int tables)
{
    slots.emplace_back(time, tables);
}

std::vector<Slot> &Restaurant::getSlots()
{
    return slots;
}

std::string Restaurant::getName() const { return name; }
std::string Restaurant::getCity() const { return location.city; }
std::string Restaurant::getArea() const { return location.area; }
std::string Restaurant::getCuisine() const { return cuisine; }
double Restaurant::getRating() const { return rating; }
double Restaurant::getCostForTwo() const { return costForTwo; }
bool Restaurant::getIsVeg() const { return isVeg; }

std::string Restaurant::serialize() const
{
    std::stringstream ss;
    ss << name << "," << location.serialize() << "," << cuisine << "," << rating << "," << costForTwo << "," << isVeg;
    for (const auto &slot : slots)
    {
        ss << "," << slot.serialize();
    }
    return ss.str();
}

Restaurant Restaurant::deserialize(const std::string &data)
{
    std::stringstream ss(data);
    std::string name, locData, cuisine;
    double rating, costForTwo;
    bool isVeg;
    std::getline(ss, name, ',');
    std::getline(ss, locData, ',');
    Location loc = Location::deserialize(locData);
    std::getline(ss, cuisine, ',');
    ss >> rating;
    ss.ignore();
    ss >> costForTwo;
    ss.ignore();
    ss >> isVeg;
    ss.ignore();
    Restaurant restaurant(name, loc, cuisine, rating, costForTwo, isVeg);
    std::string slotData;
    while (std::getline(ss, slotData, ','))
    {
        restaurant.addSlot(Slot::deserialize(slotData).time, Slot::deserialize(slotData).availableTables);
    }
    return restaurant;
}
