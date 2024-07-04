#include "BookingSystem.h"
#include <iostream>

void BookingSystem::run()
{
    // Simulate the operations here
    // Register a few restaurants
    Location loc1("New York", "Manhattan");
    Restaurant r1("Tasty Bites", loc1, "Italian", 4.5, 50, false);
    manager.registerRestaurant(r1);
    manager.addSlot("Tasty Bites", "2024-07-01 12:00", 5);
    manager.addSlot("Tasty Bites", "2024-07-01 13:00", 5);

    Location loc2("New York", "Brooklyn");
    Restaurant r2("Green Delight", loc2, "Vegan", 4.0, 40, true);
    manager.registerRestaurant(r2);
    manager.addSlot("Green Delight", "2024-07-01 12:00", 5);
    manager.addSlot("Green Delight", "2024-07-01 13:00", 5);

    // Search for restaurants
    auto results = manager.searchRestaurants("New York", "Manhattan", "Italian");
    std::cout << "Search results for Italian restaurants in Manhattan, New York:" << std::endl;
    for (const auto &res : results)
    {
        std::cout << "Restaurant: " << res.getName() << std::endl;
    }

    // Get slots for a restaurant
    auto slots = manager.getSlots("Tasty Bites");
    std::cout << "Available slots for Tasty Bites:" << std::endl;
    for (const auto &slot : slots)
    {
        std::cout << "Time: " << slot.time << ", Available tables: " << slot.availableTables << std::endl;
    }

    // Book a table
    if (manager.bookTable("Tasty Bites", "2024-07-01 12:00", 4))
    {
        std::cout << "Table booked successfully at Tasty Bites at 12:00 PM on 2024-07-01." << std::endl;
    }
    else
    {
        std::cout << "Failed to book table at Tasty Bites at 12:00 PM on 2024-07-01." << std::endl;
    }
}
