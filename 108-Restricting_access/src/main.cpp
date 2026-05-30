#include <iostream>
#include <string>

using namespace std;

class Square {
  public:
    Square(double side);

    void set_side(double side) {
        if (side < 0) {
            std::cout << "side value cannot be negative";
            return;
        }
        Square::side = side;
        Square::area = side * side;
    }

    double get_side() const {
        return side;
    }

  private:
    double side;
    double area;
    // Your code here
};

Square::Square(double side) {
    set_side(side);
}

void print(Square* square) {
    cout << "Square: side=" << square->get_side() << " area=" << square->get_side() << endl;
}

int main() {
    Square s(4);

    print(&s);

    // s.side = 2.0;
    print(&s);

    // s.side = -33.0;
    print(&s);

    return 0;
}