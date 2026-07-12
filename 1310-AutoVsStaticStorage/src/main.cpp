#include <iostream>

// Declares a void fun(void) function
void fun(void) {
    // Declares an automatic int variable named var, initialized to 99
    int a = 99;
    // Declares a static int variable
    static int s = 99;
    // Prints both the automatic variable as well as the static one
    std::cout << "automatic = " << ++a << ", static = " << ++s << '\n';
}

int main(void) {
    for (auto i = 0; i < 5; i++) {
        fun();
    }
    return 0;
}
