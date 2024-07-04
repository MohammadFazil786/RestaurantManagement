#include "Slot.h"
#include <sstream>

Slot::Slot(std::string t, int tables) : time(t), availableTables(tables) {}

bool Slot::bookTable(int n)
{
    if (availableTables >= n)
    {
        availableTables -= n;
        return true;
    }
    return false;
}

std::string Slot::serialize() const
{
    return time + "," + std::to_string(availableTables);
}

Slot Slot::deserialize(const std::string &data)
{
    std::stringstream ss(data);
    std::string time;
    int availableTables;
    std::getline(ss, time, ',');
    ss >> availableTables;
    return Slot(time, availableTables);
}
