#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

double unset = std::numeric_limits<double>::quiet_NaN();

class Line2D;

class Point2D {
  public:
    Point2D(double x, double y);
    Point2D() : x(unset), y(unset) {}

    std::string to_string() const;

  private:
    friend std::istream& operator>>(std::istream& in, Point2D& p);
    friend class Line2D;

    double x;
    double y;
};

Point2D::Point2D(double x, double y) : x(x), y(y) {}

std::string Point2D::to_string() const {
    std::ostringstream oss;
    oss << "x=" << x << " y=" << y;
    return oss.str();
}

class Line2D {
  public:
    Line2D(double slope, double y_intercept);
    Line2D(Point2D pointA, Point2D pointB);
    std::string to_string() const;

  private:
    double slope;
    double y_intercept;
};

Line2D::Line2D(double slope, double y_intercept): slope(slope), y_intercept(y_intercept) {}

Line2D::Line2D(Point2D pointA, Point2D pointB) {
    slope = (pointB.y - pointA.y) / (pointB.x - pointA.x);
    y_intercept = pointA.y - slope * pointA.x;
}

std::string Line2D::to_string() const {
    std::ostringstream oss;
    oss << "y = " << slope << "x " << (y_intercept < 0 ? "- " : "+ ") << std::abs(y_intercept);
    return oss.str();
}

std::ostream& operator<<(std::ostream& out, Point2D& p) {
    out << p.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, Line2D& line) {
    out << line.to_string();
    return out;
}

std::istream& operator>>(std::istream& in, Point2D& p) {
    // 1. read the line
    std::string line;
    std::getline(in, line);

    // 2. read space-separated values
    char delim(' ');
    std::string token;
    std::istringstream iss{line};
    double* values[]{&p.x, &p.y};
    for (size_t i = 0; i < std::size(values) && std::getline(iss, token, delim); i++) {
        // std::getline allows to specify the delim character but returns only std::string
        std::istringstream ss{token};

        double value;
        if (ss >> value) {
            *values[i] = value;
        }
    }
    return in;
}

int main() {
    // 1. reand the points
    Point2D p1, p2;
    std::cin >> p1 >> p2;

    // 2. construct a line
    Line2D l1{p1,p2};

    // 3. print the line
    std::cout << l1 << "\n";
    return 0;
}
