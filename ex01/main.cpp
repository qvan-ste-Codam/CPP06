#include <iostream>

#include "Serializer.hpp"

int main(void) {
    Data dataBefore = Data{"Type"};

    std::cout << dataBefore.name << '\n';
    uintptr_t ptr = Serializer::serialize(&dataBefore);

    Data *dataAfter = Serializer::deserialize(ptr);
    std::cout << dataAfter->name << std::endl;
}
