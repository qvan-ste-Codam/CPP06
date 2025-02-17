#include "ScalarConverter.hpp"

#include <iomanip>
#include <iostream>
#include <string>

void ScalarConverter::printValues(int asInt, char asChar, double asDouble,
                                  float asFloat) {
    std::cout << std::setprecision(5) << "int: " << asInt << '\n'
              << "double: " << asDouble << '\n'
              << "float: " << asFloat << "\n"
              << "char: " << asChar << std::endl;
};

void ScalarConverter::handleChar(std::string &input) {
    auto asChar = static_cast<char>(input[0]);
    auto asInt = static_cast<int>(asChar);
    auto asDouble = static_cast<double>(asChar);
    auto asFloat = static_cast<float>(asChar);

    printValues(asInt, asChar, asDouble, asFloat);
}

void ScalarConverter::convert(std::string &input) {
    if (input.length() == 1 && std::isprint(input[0])) {
        handleChar(input);
    };
    
}
