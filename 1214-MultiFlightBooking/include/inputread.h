#pragma once

#include <iostream>
#include <sstream>
#include <string>

inline bool read_uint(std::istringstream& iss, uint& out,
                      const std::string& err) {
    int value;
    iss >> value;
    // we are reading a uint
    if (0 <= value && value <= 1000) {
        out = value;
        return true;
    }
    std::cout << err;
    return false;
}