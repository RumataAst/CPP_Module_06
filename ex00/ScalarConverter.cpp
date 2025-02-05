#include "ScalarConverter.hpp"
#include "Colors.hpp"

#include <stdlib.h>     /* atoi */
#include <iomanip>      /*for setprecision*/

int numbr_dots(std::string &string) {
    int n = 0;
    for (int i = 0; string[i]; ++i){
        if (string[i] == '.')
            n++;
    }
    return n;
}

int is_full_digit(std::string &string) {
    bool d = false; // check to determine if it's float or doble
    int n_dots = numbr_dots(string);
    if (n_dots > 1) {
        std::cout << "it's -1" << std::endl;
        return -1;
    }
    std::cout << string.length() << std::endl;
    for (int i = 0; string[i]; ++i) {
        if (i == 0 && (string[i] == '-' || string[i] == '+' ))
        {
            i++;
            std::cout << "I saw 0\n";
        }
        if (!isdigit(string[i]) && string[i] != '.' && string[5] == 'f') {
            std::cout << "definitely -2" << std::endl;
            return -2;
        }
        if (string[i] == '.') {
            if (string.length() - i > 8) // if number of digits after the dot is more than 8 than it's double
                d = true;
        }
        if (string[5] == 'f')
            d = true;
    }
    if (n_dots == 1) {
        if (d)
            return 1;
        std::cout << "Hey it's 2" << std::endl;
        return 2;
    }
    std::cout << "HEY ITS 0" << std::endl;
    return 0;
}

void ScalarConverter::convert(std::string &string) {
    int     number;
    float   f;
    double  d;
    char    letter = '\0';
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
}