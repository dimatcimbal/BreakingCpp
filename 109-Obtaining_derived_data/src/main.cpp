#include <cassert>
#include <iostream>

class AdHocSquare {
  public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area() const;

  private:
    double side;
};

AdHocSquare::AdHocSquare(double side) {
    AdHocSquare::set_side(side);
}

void AdHocSquare::set_side(double side) {
    if (side < 0) {
        std::cout << "warning: side value cannot be negative" << "\n";
        return;
    }
    AdHocSquare::side = side;
}

double AdHocSquare::get_area() const {
    return side * side;
}

class LazySquare {
  public:
    LazySquare(double side);
    void set_side(double side);
    double get_area();
    bool has_changed() const;

  private:
    double side;
    double area;
    bool side_changed;
};

LazySquare::LazySquare(double side) : side(-1), area(-1), side_changed(false) {
    set_side(side);
}

double LazySquare::get_area() {
    if (side_changed) {
        area = side * side;
        side_changed = false;
    }
    return area;
}

bool LazySquare::has_changed() const {
    return side_changed;
}

void LazySquare::set_side(double side) {
    if (side < 0) {
        std::cout << "warning: side value cannot be negative" << "\n";
        return;
    }
    LazySquare::side = side;
    side_changed = true;
}

int main() {
    AdHocSquare ahsq{2};
    assert(ahsq.get_area() == 4 && "AdHocSquare::get_area must be equal side^2");

    LazySquare lzsq{3};
    assert(lzsq.has_changed() && "LazySquare:: side must have changed");
    // recalcs the cached value
    assert(lzsq.get_area() == 9 && "LazySquare::get_area must be equal side^2");
    assert(!lzsq.has_changed() && "LazySquare:: side must have NOT changed");
    return 0;
}