#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <iomanip> // for setprecision
#include <cerrno>  // error

void print_exception (void) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;    
}

void    print_letter (const t_print &p_values) {

}

void    print_integer (const t_print &p_values) {

}

void    print_double (const t_print &p_values) {
    
}

void    print_float (const t_print &p_values) {
    
}




void print_values (const t_print &p_values) {
    if (std::isprint(p_values.letter))
        std::cout << "char: " << p_values.letter << std::endl;
    else if (special_word(p_values.initial_string)) {
       std::cout << "char: impossible" << std::endl;     
    }
    else 
        std::cout << "char: Non displayable" << std::endl;
    if (special_word(p_values.initial_string))
        std::cout << "int: impossible"  << std::endl;
    else
        std::cout << "int: " << p_values.number  << std::endl;
    if (p_values.number == p_values.f)
        std::cout << "float: " << p_values.f << ".0f" << std::endl;
    else
        std::cout << "float: " << p_values.f << "f" << std::endl;    

    if (p_values.number == p_values.d)
        std::cout << "double: " << p_values.d << ".0" << std::endl;
    else
        std::cout << "double: " << p_values.d << std::endl;
}