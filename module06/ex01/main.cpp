#include <iostream>
#include <stdint.h>
#include "Data.h"
#include "Serializer.hpp"

int main()
{
	Data data = {"abc", 12, false };	

	std::cout << "====Struct before serialization====\n";
	std::cout <<  data.Name << std::endl;
	std::cout <<  data.MonthlyWage << std::endl;
	std::cout <<  data.IsUnemployed << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);

	std::cout << "====Unsigned int after serialization====\n";
	std::cout <<  ptr << std::endl;

	Data *deserializedData = Serializer::deserialize(ptr);

	std::cout << "====Struct after serialization====\n";
	std::cout <<  deserializedData->Name << std::endl;
	std::cout <<  deserializedData->MonthlyWage << std::endl;
	std::cout <<  deserializedData->IsUnemployed << std::endl;
}
