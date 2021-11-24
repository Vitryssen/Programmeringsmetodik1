#include "int_buffer.h"
#include <algorithm>
#include <iostream>
#ifndef INT_BUFFER
#define INT_BUFFER
#endif 
void int_buffer::swap(int_buffer& buffer)
{
	std::swap(buffer.valuePtr, valuePtr);
	std::swap(buffer.bufferSize, bufferSize);
}
bool int_buffer::is_sorted() {
	int* previous = begin();
	for (int* i = begin() + 1; i != end(); ++i) {
		if (*i < *previous)
			return false;
		previous = i;
	}
	return true;
}
int_buffer::int_buffer(size_t size) : bufferSize(size), valuePtr(new int[size])
{

}

int_buffer::int_buffer(const int* source, size_t size) : int_buffer(size)
{
	std::copy(source, source + size, begin());
}

int_buffer::int_buffer(const int_buffer& rhs) : int_buffer(rhs.begin(), rhs.size())
{
	std::copy(rhs.begin(), rhs.end(), begin());
}

int_buffer::int_buffer(int_buffer&& rhs) noexcept : bufferSize(0), valuePtr(nullptr)
{
	swap(rhs);
}

int_buffer& int_buffer::operator=(const int_buffer& rhs) noexcept
{
	int_buffer copy = int_buffer(rhs);
	swap(copy);
	return *this;
}

int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept
{
	swap(rhs);
	return *this;
}

int& int_buffer::operator[](size_t index)
{
	return valuePtr[index];
}

const int& int_buffer::operator[](size_t index) const
{
	return valuePtr[index];
}

size_t int_buffer::size() const
{
	return bufferSize;
}

int* int_buffer::begin()
{
	return valuePtr;
}

int* int_buffer::end()
{
	return valuePtr+bufferSize;
}

const int* int_buffer::begin() const
{
	return valuePtr;
}

const int* int_buffer::end() const
{
	return valuePtr+bufferSize;
}
int_buffer int_buffer::selection_sort(int_buffer arr){
	std::cout << "sorted before: " << arr.is_sorted() << std::endl;
	for (int* i = arr.begin(); i != arr.end(); ++i) {
		int* min = i;
		for (int* j = i + 1; j != arr.end(); ++j)
			if (*j < *min) 
				min = j;
		std::swap(*i, *min);
	}
	std::cout << "sorted after: " << arr.is_sorted() << std::endl;
	return arr;
}
int_buffer::~int_buffer()
{
	delete[] valuePtr;
}
