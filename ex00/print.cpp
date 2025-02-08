#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <iomanip> // for setprecision
#include <cerrno>  // error

/*  the following function is needed for the case when the number is more than max int/ less than min int
    but double can still display it.
*/
void print_part_exception (t_print &p_values) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;   
    std::cout << "float: " << p_values.f << ".0f" << std::endl;
    std::cout << "double: " << p_values.d << ".0" << std::endl;
}

void print_full_exception (void) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;    
}

void print_values (const t_print &p_values) {
    if (special_word(p_values.initial_string) 
            || (p_values.number < 31 || p_values.number > 126)) {
       std::cout << "char: impossible" << std::endl;     
    }
    else if (std::isprint(p_values.letter))
        std::cout << "char: " << p_values.letter << std::endl;
    else 
        std::cout << "char: Non displayable" << std::endl;
        
    if (special_word(p_values.initial_string) || p_values.number == 0)
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