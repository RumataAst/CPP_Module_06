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

    std::string initial_string;
};

//ScalarConverter
bool    special_word(const std::string &string);

// case_functions.cpp
void    case_zero (void);
void    case_char(const std::string &string);
void    case_int(const std::string &string);
void    case_decimal(const std::string &string);
void    case_special(std::string &string);

//print.cpp
void    print_part_exception (t_print &p_values);
void    print_full_exception (void);
void    print_values (const t_print &print_values);

//ScalarConverter.cpp
bool    special_word(const std::string &string);
int     n_apperance(const std::string &string, char search_value);
