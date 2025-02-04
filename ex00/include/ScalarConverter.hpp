# ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter {
private:

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator = (const ScalarConverter &copy);
    ~ScalarConverter();

    static void convert(std::string &string);
};


#endif