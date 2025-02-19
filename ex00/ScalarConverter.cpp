#include "ScalarConverter.hpp"

#include <limits.h>

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

void ScalarConverter::printValues(int asInt, char asChar, double asDouble,
                                  float asFloat, int precision) {
    // Limit max precision
    if (precision > 6)
        std::cout << std::defaultfloat;
    else {
        std::cout << std::fixed << std::setprecision(precision);
    }
    // Check if valid int
    if (asDouble > INT_MAX || asDouble < INT_MIN) {
        std::cout << "int: Impossible\n";
    } else {
        std::cout << "int: " << asInt << '\n';
    }
    // Check if vaid char
    if (asChar != 0) {
        std::cout << "char: " << asChar << std::endl;
    } else {
        std::cout << "char: not printable" << std::endl;
    }
    std::cout << "double: " << asDouble << "\n"
              << "float: " << asFloat << "f\n";
};

void ScalarConverter::handleChar(std::string &input) {
    char asChar = static_cast<char>(input[0]);
    int asInt = static_cast<int>(asChar);
    double asDouble = static_cast<double>(asChar);
    float asFloat = static_cast<float>(asChar);

    printValues(asInt, asChar, asDouble, asFloat);
}

void ScalarConverter::handleFloat(std::string &input) {
    try {
        float asFloat = std::stof(input);
        double asDouble = static_cast<double>(asFloat);
        int asInt = static_cast<int>(asFloat);
        char asChar = toChar(asFloat);
        int precision = input.length() - input.find('.') - 2;

        printValues(asInt, asChar, asDouble, asFloat, precision);
    } catch (std::exception &ex) {
        std::cerr << ex.what()
                  << ": not a valid float. Type conversion not possible"
                  << std::endl;
    }
}

void ScalarConverter::handleInt(std::string &input) {
    try {
        int asInt = std::stoi(input);
        double asDouble = static_cast<double>(asInt);
        float asFloat = static_cast<float>(asInt);
        char asChar = toChar(asInt);

        printValues(asInt, asChar, asDouble, asFloat);
    } catch (std::exception &ex) {
        std::cerr << ex.what()
                  << ": not a valid int. Type conversion not possible"
                  << std::endl;
    }
}

void ScalarConverter::handleDouble(std::string &input) {
    try {
        double asDouble = std::stod(input);
        float asFloat = static_cast<float>(asDouble);
        int asInt = static_cast<int>(asFloat);
        char asChar = toChar(asDouble);
        int precision = input.length() - input.find('.') - 1;

        printValues(asInt, asChar, asDouble, asFloat, precision);
    } catch (std::exception &ex) {
        std::cerr << ex.what()
                  << ": not a valid double. Type conversion not possible"
                  << std::endl;
    }
}

bool ScalarConverter::isInfinityorNaN(std::string &input) {
    return input == "inf" || input == "+inf" || input == "-inf" ||
           input == "nan" || input == "inff" || input == "+inff" ||
           input == "-inff" || input == "nanf";
}

void ScalarConverter::handleInfinityAndNaN(std::string &input) {
    double asDouble;
    double asFloat;

    if (input == "nan" || input == "nanf") {
        asDouble = std::numeric_limits<double>::quiet_NaN();
        asFloat = std::numeric_limits<float>::quiet_NaN();

    } else {
        asDouble = input[0] == '-' ? -std::numeric_limits<double>::infinity()
                                   : std::numeric_limits<double>::infinity();
        asFloat = input[0] == '-' ? -std::numeric_limits<float>::infinity()
                                  : std::numeric_limits<float>::infinity();
    }
    std::cout << "int: Impossible\n"
              << "char: Non displayable\n"
              << "double: " << asDouble << "\n"
              << "float: " << asFloat << 'f' << std::endl;
}

bool ScalarConverter::isValidDot(std::string &input) {
    size_t dotIndex = input.find_first_of('.');

    // Is not first or last char
    if (dotIndex == 0 || dotIndex == input.length() - 1) {
        return false;
    }
    // Is not only dot
    if (dotIndex != input.find_last_of('.')) {
        return false;
    };
    // Next char is not a number
    if (!std::isdigit(input[dotIndex + 1])) {
        return false;
    }
    return true;
}

bool ScalarConverter::isValidInput(std::string &input) {
    // Input is a char
    if (input.length() == 1 && std::isprint(input[0])) {
        return true;
    };
    // Contains invalid dot
    if (input.find('.') != std::string::npos && !isValidDot(input))
        return false;
    for (char c : input) {
        switch (c) {
            case '+':
                // + is not first character
                if (input.find_last_of('+') != 0) {
                    return false;
                }
                break;
            case '-':
                // - is not first character
                if (input.find_last_of('-') != 0) {
                    return false;
                }
                break;
            case 'f':
                // f is not last character
                if (input.find_first_of('f') != input.length() - 1) {
                    return false;
                }
                break;
                // Dot is already checked for validity
            case '.':
                continue;
            default:
                // Char is not a digit
                if (!std::isdigit(c)) {
                    return false;
                }
        }
    }
    return true;
}
void ScalarConverter::convert(std::string &input) {
    if (isInfinityorNaN(input)) {
        handleInfinityAndNaN(input);
    };
    if (!isValidInput(input)) {
        std::cerr << "Input is invalid" << std::endl;
        return;
    }
    if (input.length() == 1) {
        int asChar = static_cast<char>(input[0]);
        // Check if char or int
        asChar <= '0' || asChar >= '9' ? handleChar(input) : handleInt(input);
    } else if (input.find('.') != std::string::npos || input.ends_with('f')) {
        // Check if float or double
        input.ends_with('f') ? handleFloat(input) : handleDouble(input);
    } else {
        handleInt(input);
    }
}
