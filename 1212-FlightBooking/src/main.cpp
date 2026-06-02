#include <iostream>
#include <sstream>

class FlightBooking {
  public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool canceReservations(int number_ob_seats);

  private:
    uint get_percentage() const;

    int id;
    int capacity;
    int reserved;
};

void FlightBooking::printStatus() {
    // print report here
    std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << get_percentage()
              << "%) seats reserved" << "\n";
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
    : id(id), capacity(capacity), reserved(reserved) {
    // Save data to members
}

uint FlightBooking::get_percentage() const {
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

bool FlightBooking::canceReservations(int number_ob_seats) {
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

    std::string command;
    while (command != "quit") {
        booking.printStatus();
        std::cerr << "What would you like to do?:\n";

        // read the whole line till '\n'
        std::getline(std::cin, line);

        // read the command from the line
        std::istringstream iss{line};
        iss >> command;

        bool result{false};
        if (command == "add") {
            // read the arg
            int number_of_seats;
            iss >> number_of_seats;
            result = booking.reserveSeats(number_of_seats);

        } else if (command == "cancel") {
            // read the arg
            int number_of_seats;
            iss >> number_of_seats;
            result = booking.canceReservations(number_of_seats);

        } else if (command == "quit") {
            break;
        }

        if (!result) {
            std::cout << "Cannot perform this operation\n";
        }
    }

    return 0;
}
