#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <string>

class ScalarConverter {
   public:
    ScalarConverter() = delete;

    static void convert(std::string &input);

   private:
    static void printValues(int asInt, char asChar, double asDouble,
                            float asFloat);
    static int toInt(std::string &input);
    static void handleChar(std::string &input);
    static int toDouble(std::string &input);
    static int toFloat(std::string &input);
};

#endif
