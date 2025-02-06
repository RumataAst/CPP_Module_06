#include "Colors.hpp"
#include "ScalarConverter.hpp"
#include <iostream> 
#include <cstring> //conversion from char * to ctd::string

int main(int ac, char *argv[]) {
    if (ac == 2) {
        std::cout << KGRN << "Program should take 1 input.\n" 
            <<  "Define which scalar type it is:  char; int; float; double"
            << " and using static method convert in class ScalarConverter output it in the remaining scalar types\n" 
            << KGRN << std::endl;
            std::string string = argv[1];
            ScalarConverter::convert(string);
    }
    else {
        std::cerr << KRED << "Input should be 1 of the scalar types: char; int; float; double. Example: ./ScalarConverter 0\n" << KRED;
    }
    return 0;
}