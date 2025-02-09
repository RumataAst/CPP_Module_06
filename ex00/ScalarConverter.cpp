#include "Colors.hpp"
#include "ScalarConverter.hpp"

#include <iostream>

#define CASE_ZERO       0;
#define CASE_CHAR       1;
#define CASE_INT        2;
#define CASE_DECIMAL    3;
#define CASE_SPECIAL    4;


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    (void)copy;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &copy){
        if (this != &copy) {}
        return *this;
}
ScalarConverter::~ScalarConverter() {}


bool    special_word(const std::string &string) {
    std::string special_words[8] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan", "inf", "inff"};

    for (size_t i = 0; i < 8; ++i) {
        if (string == special_words[i])
            return true;
    }
    return false;
}


int n_apperance(const std::string &string, char search_value) {
    int n_apperance = 0;
    for (size_t i = 0; string[i]; ++i) {
        if (string[i] == search_value)
            n_apperance++;
    }
    return n_apperance;
}

int check_for_type(std::string &string) {
    int n_dots = n_apperance(string, '.');

    if (special_word(string)){
        return CASE_SPECIAL;
    }
    if (string.length() == 1 && string[0] == '0') {
        return CASE_ZERO;
    } 
    if (string.length() == 1 
        && (std::isprint(string[0]) && !std::isdigit(string[0]))) {
        return CASE_CHAR;
    }
    if (n_dots == 0) {
        return CASE_INT;
    }
    else
        return CASE_DECIMAL;
}

void ScalarConverter::convert(std::string &string) {
    switch (check_for_type(string)) {
        case 0:
            // std::cout << KYEL << "TESTING PHASE Zero" << RST << std::endl;
            case_zero();
            break;
        case 1:
            // std::cout << KYEL << "TESTING PHASE char" << RST << std::endl;
            case_char(string);
            break;
        case 2:
            // std::cout << KYEL << "TESTING PHASE int" << RST << std::endl;
            case_int(string);
            break;
        case 3:
            // std::cout << KYEL << "TESTING PHASE decimal" << RST << std::endl;
            case_decimal(string);
            break;
        case 4:
            // std::cout << KYEL << "TESTING PHASE special" << RST << std::endl;
            case_special(string);
            break;

    }
}