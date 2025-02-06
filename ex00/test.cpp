#include <iostream>   // std::cin, std::cout
#include <string>     // std::string, std::stoul, std::getline

int main ()
{
  std::string str;
  std::cout << "Enter an unsigned number: ";
  std::getline (std::cin,str);
  
    double  ul =  std::strtod(str.c_str(),NULL);


    int     number = static_cast<int>(ul);
    float   f = static_cast<float>(ul);
    double  d = static_cast<double>(ul);
    char    letter = static_cast<char>(ul);
  
  std::cout << "You entered: " << ul << '\n';

    std::cout << "int number :" << number  << std::endl;
    std::cout << "float : " << f << std::endl;
    std::cout << "double :" << d << std::endl;
    std::cout << "char :" << letter << std::endl;


  return 0;
}