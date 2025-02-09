#include "Base.hpp"
#include "A_B_C.hpp"
#include <cstdlib> // for rand
#include <ctime>   // rand


Base::~Base() {}

Base *Base::generate(void) {
        srand(time(NULL));
        int random = (rand() % 3);

        if (random == 0) {
                return new A;
        }
        else if (random == 1){
                return new B;                
        }
        else if (random == 2){
                return new C;                
        }
        else {
                std::cerr << "Random failed" << std::endl;
                return NULL;
        }
}

void Base::identify(Base* p) {
        if (dynamic_cast<A*>(p)) {
                std::cout << "Class A" << std::endl;
        }
        else if (dynamic_cast<B*>(p)) {
                std::cout << "Class B" << std::endl;
        }
        else if (dynamic_cast<C*>(p)) {
                std::cout << "Class C" << std::endl;
        }
        else
                std::cout << "According to exercise the only one left is Base" << std::endl;
}

void Base::identify(Base& p) {
        int check = 0;
        try {
                (void)dynamic_cast<A&>(p);
                std::cout << "Class A" << std::endl;
        }
        catch (...) {
                check++;
        }
        try {
                (void)dynamic_cast<B&>(p);
                std::cout << "Class B" << std::endl;
        }
        catch (...) {
                check++;
        }
        try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Class C" << std::endl;
        }
        catch (...) {
                check++;
        }
        if (check == 3)
                std::cout << "According to exercise the only one left is Base" << std::endl;
}