#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Fraction {
  public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator){}
    std::string to_string() const;
    double to_double() const;
    int numerator;
    int denominator;
};

std::string Fraction::to_string() const {
    std::ostringstream oss;
    const int whole = numerator / denominator;
    const int reminder = numerator % denominator;

    if (std::abs(whole) > 0) {
        oss << whole << ' ';
    }

    if (std::abs(reminder) > 0) {
        // nominator, if there is a whole part - it carries out a negative sign
        oss << (std::abs(whole) > 0 ? std::abs(reminder) : reminder)
            << "/"
            // denominator
            << std::abs(denominator) << ' ';
    }

    double d = to_double();

    oss << "is "
        // decimal value
        << d
        // decimal part
        << (d == static_cast<int>(d) ? ".0" : "")
        // the text
        << " in decimal";
    return oss.str();
}

double Fraction::to_double() const {
    return (numerator * 1.0) / denominator;
}

int main() {
    // complete line till '\n'
    std::string line;
    std::getline(std::cin, line);

    Fraction f{0, 1};
    int* values[] = {&f.numerator, &f.denominator};

    // parsing loop
    std::string token;
    std::istringstream iss{line};
    for (int i = 0; std::getline(iss, token, '/') && i < 2; i++) {
        int val;
        std::istringstream ss{token};
        if (ss >> val) {
            *values[i] = val;
        }
    }

    std::cout << f.to_string() << "\n";
    return 0;
}
