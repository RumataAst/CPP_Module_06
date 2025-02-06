#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>

void print_char(std::string &string, t_print &print_var) {
    print_var.letter = string[0];

    print_var.number = static_cast<int>(print_var.letter);
    print_var.f = static_cast<float>(print_var.letter);
    print_var.d = static_cast<double>(print_var.letter);


    std::cout << "char: " << print_var.letter << std::endl;
    std::cout << "int: " << print_var.number << std::endl;
    std::cout << "float: " << print_var.f << std::endl;
    std::cout << "double: " << print_var.d << std::endl;
}

void print_int(std::string &string, t_print &print_var) {
    print_var.number = std::atoll(string.c_str());

    if (print_var.number < 33 || print_var.number > 126) {
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        print_var.letter = static_cast<char>(print_var.number);
        std::cout << "char: " << print_var.letter << std::endl;
    }
    print_var.f = static_cast<float>(print_var.number);
    print_var.d = static_cast<double>(print_var.number);


    std::cout << "int: " << print_var.number << std::endl;
    std::cout << "float: " << print_var.f << std::endl;
    std::cout << "double: " << print_var.d << std::endl;
}
