//Description: This library allows you to read different data types from raw memory pointer
//Author: PogromistDev

#pragma once

typedef unsigned char byte;
typedef signed char sbyte;

class Memory
{
private:
	void * memPtr;
	long size;
	bool throwOutOfBoundsException = false;
public:
	Memory(void * memPtr);
    Memory(void * memPtr, long size);

	//Reading data

	template <typename T>
	T Read(unsigned int offset)
	{
		if (throwOutOfBoundsException)
		{
			if ((offset + sizeof(T) <= size))
			{
				return *((T*)((char*)memPtr + offset));
			}
			else
			{
				throw "Out of range";
			}
		}

		return *((T*)((char*)memPtr + offset));
	}

	//Reading array data

	template <typename T>
	T * Read(unsigned int offset, unsigned int size)
	{
		T * allocatedArray;
		allocatedArray = new T[size];
		for (unsigned int i = 0; i < size; i++)
		{
			allocatedArray[i] = Read<T>(offset + i);
		}

		return allocatedArray;
	}

	//Writing data

	template <typename T>
	void Write(unsigned int offset, T value)
	{
		*((T*)((char*)memPtr + offset)) = value;
	}

};