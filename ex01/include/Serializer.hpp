#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
	int		number;
    int     answer;
	char	letter;
};

class Serializer {
private:
    Serializer();
    Serializer(const Serializer &copy);
    Serializer &operator=(const Serializer &source);

public:
    ~Serializer();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};