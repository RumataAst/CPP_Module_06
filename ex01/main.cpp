#include "Serializer.hpp"


int main(void) {
    Data        data_inst;
	Data		*data_ptr = &data_inst;
	uintptr_t	numPtr;

    data_ptr->answer = 42;
    data_ptr->number = 14;
    data_ptr->letter = 'L';
    numPtr = Serializer::serialize(data_ptr);

    std::cout << "Original data_ptr address  : " << data_ptr << std::endl;
    std::cout << "Address of numPtr variable: " << &numPtr << std::endl;
    std::cout << "Value stored in numPtr    : " << numPtr << std::endl;
    std::cout << "Deserialized pointer      : " << Serializer::deserialize(numPtr) << std::endl;

    if (data_ptr == Serializer::deserialize(numPtr)) {
        std::cout << "Success: Deserialized pointer matches original" << std::endl;
    } else {
        std::cout << "Error: Addresses do not match!" << std::endl;
    }

    uintptr_t nextIntPtr = numPtr;
    int* numValuePtr = reinterpret_cast<int*>(nextIntPtr);
    std::cout << "Value at next int pointer : " << *numValuePtr << std::endl;
    nextIntPtr = numPtr + sizeof(int);
    int* numValuePtr_2 = reinterpret_cast<int*>(nextIntPtr);
    std::cout << "Value after ineration : " << *numValuePtr_2 << std::endl;

    return 0;
}