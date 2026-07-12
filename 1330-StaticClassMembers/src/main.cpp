#include <cstdint>
#include <iostream>
#include <string>

class Counter {
  public:
    // Declares a default constructor that increments the shared count
    Counter();

    // Declares a destructor that decrements the shared count
    ~Counter();

    // Declares a static int get_count() method returning the shared count
    static uint32_t get_count() {
        return count;
    }

  private:
    // Declares a static int data member to track the number of live instances
    static uint32_t count;
};

Counter::Counter() {
    count++;
}

Counter::~Counter() {
    count--;
}

// Defines the static data member out-of-class (required pre-C++17)
uint32_t Counter::count = 0;

int main() {
    // Constructs three Counter instances in nested scopes, printing
    // Counter::get_count() after each construction and after each
    // instance goes out of scope
    {
        Counter c1{};
        std::cout << "The count is " << Counter::get_count() << "\n";

        Counter c2{};
        std::cout << "the count is " << Counter::get_count() << "\n";

        Counter c3{};
        std::cout << "the count is " << Counter::get_count() << "\n";
    }

    std::cout << "the count is " << Counter::get_count() << "\n";
    return 0;
}
