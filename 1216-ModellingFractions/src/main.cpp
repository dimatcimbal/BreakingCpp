#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Fraction {
    Fraction(int numerator, int denominator);
    std::string to_string() const;
    double to_double() const;
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator)
    : numerator(numerator), denominator(denominator) {}

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

Fraction read_fraction(std::istream& in) {
    // 1. create target to read to
    Fraction f{0, 1};
    int* values[] = {&f.numerator, &f.denominator};

    // 2. read line till the next one '\n'
    std::string line;
    std::getline(in, line);

    // 3. parse the line with a custom delimiter '/'
    char delim('/');
    std::string token;
    std::istringstream iss{line};

    for (size_t i = 0; std::getline(iss, token, delim) && i < std::size(values); i++) {
        int val;
        std::istringstream ss{token};
        if (ss >> val) {
            *values[i] = val;
        }
    }

    return f;
}

int main() {
    Fraction f = read_fraction(std::cin);
    std::cout << f.to_string() << "\n";
    return 0;
}
