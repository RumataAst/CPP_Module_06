#include "ScalarConverter.hpp"
#include "Colors.hpp"

#include <stdlib.h>     /* atoi */
#include <iomanip>      /*for setprecision*/
#include <cstring>      /* strlen */
#include <limits.h>     /* limits */

int numbr_dots(std::string &string) {
    int n = 0;
    for (int i = 0; string[i]; ++i){
        if (string[i] == '.')
            n++;
    }
    return n;
}

bool    check_for_extreme (std::string &string) {
    bool check = false;
    if (string == "-inff" || string == "-inf" || string == "+inf" 
        || string == "+inff" || string == "nan" || string == "nanf")
            {
                std::cout <<"char : impossible" << std::endl;
                std::cout <<"int : impossible" << std::endl;
                std::cout <<"float : nanf" << std::endl;
                std::cout <<"double : nan" << std::endl;
                check = true;
            }
    return check;
}

int numbr_char(std::string &string) {
    int n_string = 0;
    for (size_t i = 0; string[i]; ++i) {
        if ((isprint(string[i]) && !isdigit(string[i])) && (i != strlen(string.c_str())  &&  string[string.length()] != 'f') && string[i] !='.')
            n_string++;
        if (n_string >= 2)
            return n_string;
    }
    return n_string;
}

int is_full_digit(std::string &string) {
    bool d = false; // check to determine if it's float or doble
    int n_dots = numbr_dots(string); // check for .
    int n_char = numbr_char(string); // check for string
    if (n_dots > 1 || n_char >= 2) {
        return -1;
    }
    for (int i = 0; string[i]; ++i) {
        if (i == 0 && (string[i] == '-' || string[i] == '+' ))
        {
            i++;
        }
        if (!isdigit(string[i]) && string[i] != '.' && string[string.length()] == 'f') {
            return -2;
        }
        if (string[i] == '.') {
            if (string.length() - i > 8)
                d = true;
        }
        if (string[5] == 'f')
            d = true;
    }
    if (n_dots == 1) {
        if (d)
            return 1;
        return 2;
    }
    return 0;
}




void ScalarConverter::convert(std::string &string) {
    int     number;
    float   f;
    double  d;
    char    letter = '\0';
    if (check_for_extreme(string) == 1)
        return ;


    if (is_full_digit(string) == -1) {
        std::cout << KRED << "Please add valid input" << std::endl;
        return ;
    }

    if (string.length() == 1 && (isprint(string[0]) && !isdigit(string[0]))) {
        letter = string[0];
        number = static_cast<int>(letter);
        f = static_cast<float>(letter);
        d = static_cast<double>(letter);
        std::cout <<"char : " << letter << std::endl;
        std::cout <<"int : " << number << std::endl;
        std::cout <<"float : " << f << ".0f" << std::endl;
        std::cout <<"double : " << d << ".0" << std::endl;
    }
    else if (is_full_digit(string) == 0) {
        number = atoi(string.c_str());

        if (number < 33 || number > 126)
            std::cout <<  "char : Non displayable" << std::endl;
        else {
            letter = static_cast<char>(number);
            std::cout <<"letter : " << letter << std::endl;
        }
        f = static_cast<float>(number);
        d = static_cast<double>(number);
        std::cout <<"int : " << number << std::endl;
        std::cout <<"float : " << f << ".0f" << std::endl;
        std::cout <<"double : " << d << ".0" << std::endl;
    }
    else if (is_full_digit(string) == 2) {
        f = atof(string.c_str());
        number = static_cast<int>(f);
        if (number < 33 || number > 126)
            std::cout <<  "char : Non displayable" << std::endl;
        else {
            letter = static_cast<char>(f); 
            std::cout <<"letter : " << letter << std::endl;
        }
        d = static_cast<double>(f);
        std::cout <<"int : " << number << std::endl;
        std::cout <<"float : " << f << std::setprecision(7) << "f" << std::endl;
        std::cout <<"double : " << d << std::setprecision(15) << std::endl;
    }
    else if (is_full_digit(string) == 1) {
        d = atof(string.c_str());
        number = static_cast<int>(d);
        if (number < 33 || number > 126)
            std::cout <<  "char : Non displayable" << std::endl;
        else {
            letter = static_cast<char>(d);
            std::cout <<"letter : " << letter << std::endl;
        }
        f = static_cast<double>(d);
        std::cout <<"int : " << number << std::endl;
        std::cout <<"float : " << f  << std::setprecision(7) <<"f" << std::endl;
        std::cout <<"double : " << d << std::setprecision(15) << std::endl;
    }
    else {
        std::cout << KRED << "Input incorrect" << std::endl;
    }
}