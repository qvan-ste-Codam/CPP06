
#include <iostream>
#include <random>

#include "Base.hpp"

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);
    int num = dis(gen);

    switch (num) {
        case 0:
            std::cout << "Created pointer is of type A" << std::endl;
            return dynamic_cast<Base*>(new A);
        case 1:
            std::cout << "Created pointer is of type B" << std::endl;
            return dynamic_cast<Base*>(new B);
        default:
            std::cout << "Created pointer is of type C" << std::endl;
            return dynamic_cast<Base*>(new C);
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr) {
        std::cout << "Identified pointer is of type A" << std::endl;
    } else if (dynamic_cast<B*>(p) != nullptr) {
        std::cout << "Identified pointer is of type B" << std::endl;
    } else if (dynamic_cast<C*>(p) != nullptr) {
        std::cout << "Identified pointer is of type C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified reference is of type A" << std::endl;
    } catch (const std::bad_cast&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Identified reference is of type B" << std::endl;
        } catch (const std::bad_cast&) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Identified reference is of type C" << std::endl;
            } catch (const std::bad_cast&) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main(void) {
    Base* base = generate();
    identify(base);
    identify(base);
    delete base;
}
