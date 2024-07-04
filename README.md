Restaurant Booking System Project


Project Overview: 

The Restaurant Booking System is a comprehensive software solution designed to streamline the process of table reservations at restaurants. This system is akin to popular platforms like Zomato and Swiggy, offering features for both restaurant owners and customers.

Key Features:

Restaurant Registration: Restaurant owners can register their establishments by providing essential details such as name, location, cuisine type, rating, cost for two, and whether the restaurant offers vegetarian options.

Slot Management: Owners can add available time slots for table bookings, with each slot representing a 1-hour window. The system ensures that slots can be added only for up to a predefined number of days in the future (e.g., 30 days).

Search Functionality: Customers can search for restaurants based on various attributes such as name, city, area, cuisine, rating, and cost for two.

Table Booking: After selecting a restaurant, customers can book a table for a specified number of people, provided there is availability in the chosen time slot. The booking operation is thread-safe, ensuring concurrency handling for multiple parallel booking requests.

Data Persistence: The system saves restaurant and slot data to a file, ensuring that all information is persisted between application runs. This data is loaded from the file upon system startup.

Technical Implementation:

Programming Language: C++

Concurrency Handling: Utilized std::mutex and std::lock_guard to ensure thread safety during booking operations.

File Handling: Implemented serialization and deserialization for saving and loading data to/from files.

Object-Oriented Design: Employed principles of object-oriented design, with classes such as Location, Slot, Restaurant, RestaurantManager, and BookingSystem.

Classes and Responsibilities:

Location: Manages the city and area details of a restaurant.

Slot: Represents a booking slot with the number of available tables and includes methods to book a table.

Restaurant: Contains details of the restaurant and manages a list of booking slots.

RestaurantManager: Handles the registration of restaurants, searching for restaurants, adding slots, and booking tables. It also manages data persistence.

BookingSystem: Orchestrates the entire booking process, demonstrating the functionality of the system.

Demonstration of Features:

Registering Restaurants: Adding new restaurants to the system.

Adding Slots: Defining available booking slots for each restaurant.

Searching for Restaurants: Finding restaurants based on various criteria.

Booking Tables: Making table reservations and ensuring that the booking process is thread-safe.

Persistent Storage: Saving and loading restaurant data to/from a file.

Conclusion:

This project showcases the ability to design and implement a full-fledged booking system with a focus on concurrency, file handling, and object-oriented design principles. It demonstrates practical problem-solving skills and the capability to develop scalable and reliable software solutions.
