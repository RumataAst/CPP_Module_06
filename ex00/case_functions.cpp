#include "ScalarConverter.hpp"
#include <climits>  // Int max min
#include <cfloat>   // Double max min
#include <cstdlib>  // for strol and strtod

int f_position (const std::string &string) {
    int i = 0;
    while (string[i])
        i++;
    if (string[i-1] == 'f')
        return i;
    return -1;
}

void    case_char(const std::string &string) {
    t_print p_values;
    p_values.letter = string[0];
    p_values.number = static_cast<int>(p_values.letter);
    p_values.f = static_cast<float>(p_values.letter);
    p_values.d = static_cast<double>(p_values.letter);

    print_values(p_values);
}

void    case_int(const std::string &string) {
    t_print p_values;
    char* p_end;{};
    long  l =  std::strtol(string.c_str(), &p_end ,10);

    if (l == 0 || *p_end != '\0'
            || l > INT_MAX || l < INT_MIN) {
            if (l > INT_MAX || l < INT_MIN) {
                p_values.f = static_cast<float>(l);
                p_values.d = static_cast<double>(l); 
                print_part_exception(p_values);
            }
            else
                print_full_exception();
    }
    else {
        p_values.initial_string = string;
        p_values.number = static_cast<int>(l);
        p_values.letter = static_cast<char>(l);
        p_values.f = static_cast<float>(l);
        p_values.d = static_cast<double>(l);

        print_values(p_values);
    }
}

void    case_decimal(const std::string &string) {
    t_print         p_values;
    char*           p_end;
    std::string     string_wo_f;
    double          db;
    int             f_pos = f_position(string);
    if (f_pos != -1) {
        string_wo_f = string.substr(0, string.size()-1);
        db =  std::strtod(string_wo_f.c_str(), &p_end);
    }
    else 
        db =  std::strtod(string.c_str(), &p_end);

    if (db == 0 || *p_end != '\0'
        || db > DBL_MAX || db < DBL_MIN ) {
        print_full_exception();
    }
    else {
        p_values.initial_string = string;
        if (db > INT_MAX || db < INT_MIN)
            p_values.number = 0;
        else
            p_values.number = static_cast<int>(db);
        p_values.letter = static_cast<char>(db);
        p_values.f = static_cast<float>(db);
        p_values.d = db;

        print_values(p_values);
    }

}

void    case_zero (void) {
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: 0" << std::endl;
    std::cout << "float: 0.0f" << std::endl;
    std::cout << "double: 0.0" << std::endl;
}

void    case_special(std::string &string) {
    std::cout << "char: impossible" << std::endl;
    if (string == "-inff" || string == "+inff" || string == "nanf") {
        std::cout << "int: " << string.substr(0, string.size()-1) << std::endl;
        std::cout << "float: "<< string << std::endl;
        std::cout << "double: "<< string.substr(0, string.size()-1) << std::endl;
    }
    else if (string == "inff") {
        std::cout << "int: +" << string.substr(0, string.size()-1) << std::endl;
        std::cout << "float: +"<< string << std::endl;
        std::cout << "double: +"<< string.substr(0, string.size()-1) << std::endl;        
    }
    else if (string != "inf") {
        std::cout << "int: " << string << std::endl;
        std::cout << "float: "<< string << "f" << std::endl;
        std::cout << "double: "<< string << std::endl;
    }
    else {
        std::cout << "int: +" << string << std::endl;
        std::cout << "float: +"<< string << "f" << std::endl;
        std::cout << "double: +"<< string << std::endl;        
    }
   
}