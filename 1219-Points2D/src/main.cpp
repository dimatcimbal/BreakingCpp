#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

class Point2D {
  public:
    Point2D(double x, double y);
    std::string to_string() const;
    double to_double();
    double distance_to(Point2D other) const;

  private:
    // allow the read_point2D to access the private constructor  Point2D
    friend Point2D read_point2D(std::istream& input);
    Point2D() : x(0.0), y(0.0) {}

    double x;
    double y;
};

Point2D read_point2D(std::istream& input) {
    // 1. create target to read to
    Point2D p{};
    double* values[] = {&p.x, &p.y};

    // 2. read a line till the next one '\n'
    std::string line;
    std::getline(input, line);

    // 3. parse the line with a custom delimiter ' '
    char delim(' ');
    std::string token;
    std::istringstream iss{line};

    for (size_t i = 0; std::getline(iss, token, delim) && i < std::size(values); i++) {
        double val;
        std::istringstream ss{token};
        if (ss >> val) {
            *values[i] = val;
        }
    }

    return p;
}

double Point2D::distance_to(Point2D other) const {
    return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
}

std::string Point2D::to_string() const {
    std::stringstream oss;
    oss << "x=" << x << ", y=" << y;
    return oss.str();
}

std::ostream& operator<<(std::ostream& out, Point2D& p) {
    out << p.to_string();
    return out;
}

int main() {
    Point2D p1 = read_point2D(std::cin);
    Point2D p2 = read_point2D(std::cin);

    std::cout << std::setprecision(9) << p1.distance_to(p2) << '\n';
    return 0;
}
