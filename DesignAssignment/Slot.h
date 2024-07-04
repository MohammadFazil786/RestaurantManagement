#ifndef SLOT_H
#define SLOT_H

#include <string>

class Slot
{
public:
    std::string time;
    int availableTables;

    Slot(std::string t, int tables);

    bool bookTable(int n);
    std::string serialize() const;
    static Slot deserialize(const std::string &data);
};

#endif // SLOT_H
