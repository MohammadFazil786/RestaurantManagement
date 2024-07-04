#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include "RestaurantManager.h"

class BookingSystem
{
private:
    RestaurantManager manager;

public:
    void run();
};

#endif // BOOKINGSYSTEM_H
