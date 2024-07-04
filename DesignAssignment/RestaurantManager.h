#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include "Restaurant.h"
#include <vector>
#include <mutex>
#include <string>

class RestaurantManager
{
private:
    std::vector<Restaurant> restaurants;
    std::mutex mtx;
    const std::string fileName = "restaurants.dat";
    const int maxDaysInFuture = 30; // Example value for maximum days allowed for booking

public:
    RestaurantManager();
    ~RestaurantManager();

    void registerRestaurant(const Restaurant &restaurant);
    std::vector<Restaurant> searchRestaurants(const std::string &city, const std::string &area, const std::string &cuisine);
    bool bookTable(const std::string &restaurantName, const std::string &time, int n);
    std::vector<Slot> getSlots(const std::string &restaurantName);
    void addSlot(const std::string &restaurantName, const std::string &time, int tables);

    void saveToFile();
    void loadFromFile();
};

#endif // RESTAURANTMANAGER_H
