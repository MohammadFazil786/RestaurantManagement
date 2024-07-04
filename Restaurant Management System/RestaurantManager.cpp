#include "RestaurantManager.h"
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <ctime>
#include <iomanip>

RestaurantManager::RestaurantManager()
{
    loadFromFile();
}

RestaurantManager::~RestaurantManager()
{
    saveToFile();
}

void RestaurantManager::registerRestaurant(const Restaurant &restaurant)
{
    restaurants.push_back(restaurant);
}

std::vector<Restaurant> RestaurantManager::searchRestaurants(const std::string &city, const std::string &area, const std::string &cuisine)
{
    std::vector<Restaurant> result;
    for (const auto &restaurant : restaurants)
    {
        if (restaurant.getCity() == city && restaurant.getArea() == area && restaurant.getCuisine() == cuisine)
        {
            result.push_back(restaurant);
        }
    }
    return result;
}

bool RestaurantManager::bookTable(const std::string &restaurantName, const std::string &time, int n)
{
    std::lock_guard<std::mutex> lock(mtx);
    for (auto &restaurant : restaurants)
    {
        if (restaurant.getName() == restaurantName)
        {
            for (auto &slot : restaurant.getSlots())
            {
                if (slot.time == time && slot.bookTable(n))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

std::vector<Slot> RestaurantManager::getSlots(const std::string &restaurantName)
{
    for (auto &restaurant : restaurants)
    {
        if (restaurant.getName() == restaurantName)
        {
            return restaurant.getSlots();
        }
    }
    return {};
}

void RestaurantManager::addSlot(const std::string &restaurantName, const std::string &time, int tables)
{
    std::tm tm = {};
    std::istringstream ss(time);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");
    std::time_t slotTime = std::mktime(&tm);
    std::time_t currentTime = std::time(nullptr);
    double secondsInFuture = std::difftime(slotTime, currentTime);
    double daysInFuture = secondsInFuture / (60 * 60 * 24);

    if (daysInFuture > maxDaysInFuture)
    {
        std::cerr << "Error: Booking slots can only be added for up to " << maxDaysInFuture << " days in the future." << std::endl;
        return;
    }

    for (auto &restaurant : restaurants)
    {
        if (restaurant.getName() == restaurantName)
        {
            restaurant.addSlot(time, tables);
            return;
        }
    }
}

void RestaurantManager::saveToFile()
{
    std::ofstream file(fileName);
    for (const auto &restaurant : restaurants)
    {
        file << restaurant.serialize() << std::endl;
    }
    file.close();
}

void RestaurantManager::loadFromFile()
{
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line))
    {
        restaurants.push_back(Restaurant::deserialize(line));
    }
    file.close();
}
