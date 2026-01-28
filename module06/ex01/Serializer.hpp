#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <cstdint>
#include <iostream>
#include "Data.h"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
