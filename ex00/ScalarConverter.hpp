#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <string>

class ScalarConverter {
   public:
    ScalarConverter() = delete;

    static void convert(std::string &input);

   private:
    static void printValues(int asInt, char asChar, double asDouble,
                            float asFloat, int precision = 1);
    static void handleChar(std::string &input);
    static void handleFloat(std::string &input);
    static void handleInt(std::string &input);
    static void handleInfinityAndNan(std::string &input);
    static char toChar(int asInt);
    static bool isInfinityorNan(std::string &input);
    static bool isValidInput(std::string &input);
    static bool isValidDot(std::string &input);
};

#endif
