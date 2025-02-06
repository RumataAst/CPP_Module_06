#include "Colors.hpp"
#include "ScalarConverter.hpp"

// std::numeric_limits for limits
// std::strtof for float
// std::strtod for double 
// std::atoll for int

#include <iostream>

#define TYPE_CHAR   0;
#define TYPE_INT    1;
#define TYPE_FLOAT  2;
#define TYPE_DOUBLE 3;

//incorrect. It seems the input varies based on the type of string -inf is different from +inf?
// bool    check_for_extreme (std::string &string) {
//     bool check = false;
//     if (string == "-inff" || string == "-inf" || string == "+inf" 
//         || string == "+inff" || string == "nan" || string == "nanf")
//             {
//                 std::cout <<"char : impossible" << std::endl;
//                 std::cout <<"int : impossible" << std::endl;
//                 std::cout <<"float : nanf" << std::endl;
//                 std::cout <<"double : nan" << std::endl;
//                 check = true;
//             }
//     return check;
// }


int n_apperance(std::string &string, char search_value) {
    int n_apperance = 0;
    for (size_t i = 0; string[i]; ++i) {
        if (string[i] == search_value)
            n_apperance++;
    }
    return n_apperance;
}


/* 
    Checking if the  string is a number by going through the string and checking if it's a digit with the exceptions:
        first symbol can be '-' or '+'
        there can be one '.'
        one 'f' is allowed if it's the last and '.' is present
*/
bool    is_number(std::string &string) {
    size_t  i = 0;
    size_t  length = string.length();
    int     n_dots = n_apperance(string, '.');

    if  (n_dots > 1 || string[0] == '.')
        return false;
    if (string[i] == '+' || string[i] == '-')
        i++;
    while (string[++i]) {
        if (!std::isdigit(string[i]) && string[i] != '.' 
            && !(i == length - 1 && string[i] == 'f' && n_dots == 1 && std::isdigit(string[i-1]))) {
            return false;
        }
    }
    return true;
}

/*
    check_for_type function tries to check what format of input is there
    char if it's only 1 character and it's printable and at the same time not a digit
    for int, double and float there is additional function is_number
*/
int check_for_type(std::string &string) {
    int n_dots = n_apperance(string, '.');
    int n_fs = n_apperance(string, 'f');
 
    if (string.length() == 1 
        && (std::isprint(string[0]) && !std::isdigit(string[0]))) {
        return TYPE_CHAR;
        }
    if (is_number(string) == true) {
        if (n_dots == 0) {
            return TYPE_INT;
        }
        else if (n_fs == 1) {
            return TYPE_FLOAT;
        }
        else {
            return TYPE_DOUBLE;
        }
    }
    return -1;
}

void ScalarConverter::convert(std::string &string) {
    t_print print_var;   
    switch (check_for_type(string)) {
        case 0:
            print_char(string, print_var);
            break;
        case 1:
            print_int(string, print_var);
            break;
        case 2:
            std::cout << "Float" << std::endl;
        //     print_float(string, print_var);
            break;
        case 3:
            std::cout << "Double" << std::endl;
        //     print_double(string);
            break;
        default:
            // check_extreme
            std::cout << KRED << "Invalid input" << KRED << std::endl;
    }
}