#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Incorrect number of parameters" << std::endl;
        return 1;
    }

    auto inputString = std::string{argv[1]};
    ScalarConverter::convert(inputString);
}
