#include "FlightBooking.h"

#include <iostream>
#include <sstream>

int main() {
    int reserved = 0, capacity = 0;
    std::string line;

    // print to cerr to as cout gets used in the functional test
    std::cerr << "Provide flight capacity: ";
    std::getline(std::cin, line);
    capacity = std::stoi(line);

    // print to cerr to as cout gets used in the functional test
    std::cerr << "Provide number of reserved seats: ";
    std::getline(std::cin, line);
    reserved = std::stoi(line);

    FlightBooking booking(1, capacity, reserved);

    for (std::string command; command != "quit";) {
        std::cout << booking.to_string();
        std::cerr << "What would you like to do?:\n";

        // read the whole line till '\n'
        std::getline(std::cin, line);

        // read the command from the line
        std::istringstream iss{line};
        iss >> command;

        if (command == "quit") {
            break;
        }

        // read the arg
        int number_of_seats;
        iss >> number_of_seats;

        bool result{false};
        if (command == "add") {
            result = booking.reserveSeats(number_of_seats);

        } else if (command == "cancel") {
            result = booking.cancelReservations(number_of_seats);
        }

        if (!result) {
            std::cout << "Cannot perform this operation\n";
        }
    }

    return 0;
}
