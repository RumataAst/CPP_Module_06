# ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>

//Class with only 1 static method
class ScalarConverter {
private:

public:
    // ScalarConverter();
    // ScalarConverter(const ScalarConverter &copy);
    // ScalarConverter &operator = (const ScalarConverter &copy);
    // ~ScalarConverter();

    static void convert(std::string &string);
};


#endif
// Struct for printing
struct t_print {
    char    letter;
    int     number;
    float   f;
    double  d;
};

// Functions for printing result
void print_char(std::string &string, t_print &print_var);
void print_int(std::string &string, t_print &print_var);
