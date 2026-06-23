#include <iostream>
#include <sstream>
#include <string>

class Fraction {
  public:
    Fraction(int numerator, int denominator);
    std::string to_string() const;
    double to_double() const;

    // Available in C++20
    // std::strong_ordering operator<=>(const Fraction& other) const;
    int compare(const Fraction& other) const;

    int numerator;
    int denominator;

  private:
    void reduce();
};

Fraction::Fraction(int numerator, int denominator)
    : numerator(numerator), denominator(denominator) {}

// Available in C++20
// std::strong_ordering Fraction::operator<=>(const Fraction& other) const {
//     int lhs = numerator * other.denominator;
//     int rhs = other.numerator * denominator;
//     return lhs <=> rhs;
// }

int Fraction::compare(const Fraction& other) const {
    int lhs = numerator * other.denominator;
    int rhs = other.numerator * denominator;
    return (lhs > rhs) - (lhs < rhs);
}

// Euclidean GCD
// each step replaces (a, b) with (b, a % b).
void Fraction::reduce() {
    int a = std::abs(numerator);
    int b = std::abs(denominator);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    // a is the GCD
    numerator /= a;
    denominator /= a;
}

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
            << std::abs(denominator);
    }

    return oss.str();
}

double Fraction::to_double() const {
    return (numerator * 1.0) / denominator;
}

std::ostream& operator<<(std::ostream& os, Fraction f) {
    os << f.to_string();
    return os;
}

struct DelimBuf : std::streambuf {
    DelimBuf(std::string src, char delim) : iss(src), src(iss.rdbuf()), delim(delim) {}

  protected:
    /**
     *
      std::istream::operator>>(int&)
          │  needs characters — calls streambuf
          ▼
      std::streambuf::sgetc()
          │  get area empty? calls underflow()
          ▼
      DelimBuf::underflow()   ← our override
          │  reads from iss, skips '/', exposes next char via setg()
          ▼
      returns char to sgetc()
          │
          ▼
      std::istream parses digits until whitespace/eof, converts to int
     */
    int_type underflow() override {
        // read one character
        int_type c = src->sbumpc();

        // if eof is the delimiter - stop
        if (c == delim) {
            return traits_type::eof();
        }

        // eof when we got eof
        if (c == traits_type::eof()) {
            return traits_type::eof();
        }

        // store char in our single-char buffer and tell streambuf that one char available at buf
        buf = traits_type::to_char_type(c);
        setg(&buf, &buf, &buf + 1);
        return c;
    }

    std::istringstream iss;
    std::streambuf* src;
    char delim;
    char buf;
};

Fraction read_fraction(std::istream& input) {
    Fraction f{0, 1};
    int* values[] = {&f.numerator, &f.denominator};

    std::string line;
    std::getline(input, line);
    DelimBuf delim_buf{line, '/'};
    std::istream delim_stream(&delim_buf);

    for (auto& value : values) {
        int val;
        delim_stream >> val;
        delim_stream.clear();
        *value = val;
    }
    return f;
}

int main() {
    Fraction f1 = read_fraction(std::cin);
    Fraction f2 = read_fraction(std::cin);

    int order = f1.compare(f2);
    if (order < 0) {
        std::cout << f1 << " < " << f2 << "\n";
    } else if (order > 0) {
        std::cout << f1 << " > " << f2 << "\n";
    } else {
        std::cout << f1 << " == " << f2 << "\n";
    }

    return 0;
}
