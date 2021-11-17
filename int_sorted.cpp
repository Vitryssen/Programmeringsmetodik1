#include "int_sorted.h"
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <iostream>
#pragma once
#ifndef INT_SORTED
#define INT_SORTED

#endif // !INT_SORTED
int_sorted::int_sorted(const int* source, size_t size) : buffer(int_buffer(source, size))
{
	if (size > 1) {
		std::cout << "Sorted before: " << buffer.is_sorted() << std::endl;
		*this = sort(begin(), end());
		std::cout << "Sorted after: " << buffer.is_sorted() << std::endl;
	}
}

size_t int_sorted::size() const
{
	return buffer.size();
}

const int* int_sorted::insert(int value)
{
	buffer = merge(int_sorted(&value, 1)).buffer; //insert value and do selection sort
	return std::find(begin(), end(), value); //return index of where the value was added
}

const int* int_sorted::begin() const
{
	return buffer.begin();
}

const int* int_sorted::end() const
{
	return buffer.end();
}
int_sorted int_sorted::sort(const int* begin, const int* end)
{
	if (begin == end) 
		return int_sorted(nullptr, 0);
	if (begin == end - 1)
		return int_sorted(begin, 1);
	ptrdiff_t half = (end - begin) / 2; //pointer diff type
	const int* mid = begin + half;
	return sort(begin, mid).merge(sort(mid, end));
}
int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
	int_buffer merge_buffer = int_buffer(size() + merge_with.size());
	const int* local_iterator = begin();
	const int* merge_iterator = merge_with.begin();
	int* result_iterator = merge_buffer.begin();

	while (local_iterator != end() && merge_iterator != merge_with.end()) {
		if (*local_iterator < *merge_iterator)
			*result_iterator++ = *local_iterator++;
		else
			*result_iterator++ = *merge_iterator++;
	}
	while (local_iterator != end()) {
		*result_iterator++ = *local_iterator++;
	}
	while (merge_iterator != merge_with.end()) {
		*result_iterator++ = *merge_iterator++;
	}
	int_sorted final_result = int_sorted(nullptr, 0);
	final_result.buffer = std::move(merge_buffer);

	return final_result;
}

int_buffer int_sorted::get_buffer()
{
	return buffer;
}
