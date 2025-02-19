#include "Data.hpp"

Data::Data(const std::string& name) : name{name} {};

Data::Data(const Data& other) : name{other.name} {}

Data& ::Data::operator=(const Data & other) {
    if (this != &other) {
        this->name = other.name;
    }
    return *this;
}
