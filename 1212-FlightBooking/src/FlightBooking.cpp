#include "FlightBooking.h"

#include <iostream>
#include <sstream>

std::string FlightBooking::to_string() const {
    std::ostringstream oss;
    oss << "Flight " << id << " : " << reserved << "/" << capacity << " (" << get_percentage()
        << "%) seats reserved" << "\n";
    return oss.str();
}

uint32_t FlightBooking::get_percentage() const {
    if (capacity == 0) {
        return 100.0;
    }
    return static_cast<uint>((static_cast<double>(reserved) / capacity) * 100.0);
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    // return on negative number_of_seats
    if (number_of_seats < 0) {
        return false;
    }

    double booking_limit = 1.051 * this->capacity;

    // successful reservation
    if (this->reserved + number_of_seats < booking_limit) {
        this->reserved += number_of_seats;
        return true;
    }

    return false;
}

bool FlightBooking::cancelReservations(int number_ob_seats) {
    // return on out negative number_of_seats
    if (number_ob_seats < 0) {
        return false;
    }

    if (this->reserved - number_ob_seats >= 0) {
        this->reserved -= number_ob_seats;
        return true;
    }

    return false;
}