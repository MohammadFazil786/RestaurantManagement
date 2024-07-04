#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location
{
public:
    std::string city;
    std::string area;

    Location(std::string c, std::string a);

    std::string serialize() const;
    static Location deserialize(const std::string &data);
};

#endif // LOCATION_H
