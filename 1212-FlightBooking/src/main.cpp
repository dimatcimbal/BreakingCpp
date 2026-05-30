#include <iostream>

class FlightBooking {
  public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    uint get_percentage() const;

  private:
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

int main() {
    int reserved = 0, capacity = 0;

    // print to cerr to as cout gets used in the functional test
    std::cerr << "Provide flight capacity: ";
    std::cin >> capacity;

    // print to cerr to as cout gets used in the functional test
    std::cerr << "Provide number of reserved seats: ";
    std::cin >> reserved;

    FlightBooking booking(1, capacity, reserved);

    booking.printStatus();

    return 0;
}
