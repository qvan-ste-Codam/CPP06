#ifndef DATA_HPP
#define DATA_HPP
#include <string>

class Data {
   public:
    Data(const std::string &name = "Data");
    Data(const Data &other);
    ~Data() = default;
    Data &operator=(const Data &other);

    std::string name;
};

#endif
