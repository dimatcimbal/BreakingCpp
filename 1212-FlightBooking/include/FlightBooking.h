#include <iostream>
#include <string>

class FlightBooking {
  public:
    FlightBooking(uint id, uint capacity, uint reserved)
        : id(id), capacity(capacity), reserved(reserved) {};

    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_ob_seats);
    std::string to_string() const;

  private:
    uint32_t get_percentage() const;

    uint id;
    int capacity;
    int reserved;
};