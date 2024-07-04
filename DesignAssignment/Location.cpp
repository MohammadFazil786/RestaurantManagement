#include "Location.h"
#include <sstream>

Location::Location(std::string c, std::string a) : city(c), area(a) {}

std::string Location::serialize() const
{
    return city + "," + area;
}

Location Location::deserialize(const std::string &data)
{
    std::stringstream ss(data);
    std::string city, area;
    std::getline(ss, city, ',');
    std::getline(ss, area, ',');
    return Location(city, area);
}
