
#include "FlightBooking.h"
#include "inputread.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>

constexpr auto VALID_COMMANDS = {"create", "add", "cancel", "delete"};

// The ORDERED map is required dues to the test alphabetical ordering
void print_bookings(std::map<uint, FlightBooking>& bookings) {
    // Print the current stats of the flight bookings
    if (bookings.empty()) {
        // if no bookings - a  simple message
        std::cout << "No flights in the system\n";
    } else {
        // if has bookings - return a formated view
        for (const auto& [flight_number, flight_booking] : bookings) {
            std::cout << flight_booking.to_string();
        }
    }
}

int main() {
    // The ORDERED map is required dues to the test alphabetical ordering
    std::map<uint, FlightBooking> bookings;

    for (std::string command; command != "quit";) {
        // Start with printing current state
        print_bookings(bookings);
        std::cout << "\n";

        // read the whole line till '\n' instead of cin>>
        std::string line;
        std::getline(std::cin, line);

        // Empty line guard
        if (line.empty()) {
            std::cout << "Input cannot be empty\n";
            break;
        }

        std::istringstream iss{line};
        iss >> command;

        if (command == "quit") {
            break;
        }

        // verify the command is an expected value as all require two input values
        if (std::ranges::find(VALID_COMMANDS, command) == VALID_COMMANDS.end()) {
            std::cout
                << "ERROR Unknown operation. One of CREATE, ADD, CANCEL or DELETE is allowed.\n";
            continue;
        }

        // Read the value (v)
        uint number;
        if (!read_uint(iss, number, "Invalid flight number\n")) {
            continue;
        }

        // Assign the flight number
        uint value;
        if (!read_uint(iss, value, "Invalid flight capacity\n")) {
            continue;
        }

        if (command == "create") {
            bookings.emplace(number, FlightBooking(number, value, 0));
            continue;
        }

        auto key_pair = bookings.find(number);
        if (key_pair == bookings.end()) {
            std::cout << "Cannot perform this operation: flight " << number << " not found\n";
            continue;
        }

        auto& fb_ptr = key_pair->second;
        if (command == "add") {
            if (!fb_ptr.reserveSeats(value)) {
                std::cout << "Cannot perform this operation: capacity reached\n";
            }

        } else if (command == "cancel") {
            if (!fb_ptr.cancelReservations(value)) {
                std::cout
                    << "Cannot perform this operation: canceling number is greater than reserved\n";
            }

        } else if (command == "delete") {
            bookings.erase(number);
        }
    }

    return 0;
};
