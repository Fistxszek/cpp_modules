#include "Serializer.hpp"
#include "Data.h"
#include <cstdint>

Serializer::Serializer(void){  }
Serializer::Serializer(const Serializer &other) {  }
Serializer::~Serializer() {  }
Serializer &Serializer::operator=(const Serializer &other) 
{
	if (this == &other)
		return *this;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t serializedValue = reinterpret_cast<uintptr_t>(ptr);
	return serializedValue;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data * deserializedStructure = reinterpret_cast<Data *>(raw);
	return deserializedStructure;
}
