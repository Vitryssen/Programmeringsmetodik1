#pragma once
#include "int_buffer.h"
#ifndef INT_SORTED
#define INT_SORTED
class int_sorted {
private:
	int_buffer buffer;
public:
	/// <summary>
	/// No point sorting empty buffer, deletes instead
	/// </summary>
	int_sorted() = delete;
	/// <summary>
	/// Constructor with a given buffer and size
	/// </summary>
	/// <param name="source">pointer to buffer</param>
	/// <param name="size">size of buffer</param>
	int_sorted(const int* source, size_t size);
	/// <summary>
	/// Returns size of buffer
	/// </summary>
	/// <returns>size of buffer</returns>
	size_t size() const;
	/// <summary>
	/// Returns the insertion point.
	/// </summary>
	/// <param name="value">value to insert</param>
	/// <returns>pointer to where the value was inserted</returns>
	const int* insert(int value);
	/// <summary>
	/// Returns pointer to beginning of buffer
	/// </summary>
	/// <returns>pointer to start of buffer</returns>
	const int* begin() const;
	/// <summary>
	/// Returns pointer to end of buffer
	/// </summary>
	/// <returns>pointer to end of buffer</returns>
	const int* end() const;
	/// <summary>
	/// Sorts the buffer
	/// </summary>
	/// <param name="begin">pointer to start of buffer</param>
	/// <param name="end">pointer to end of buffer</param>
	/// <returns>a sorted buffer</returns>
	int_sorted sort(const int* begin, const int* end);
	/// <summary>
	/// Merge two int_sorted
	/// </summary>
	/// <param name="merge_with">int_sorted to merge with</param>
	/// <returns>merged int_sorted</returns>
	int_sorted merge(const int_sorted& merge_with) const;
	/// <summary>
	/// Get buffer object
	/// </summary>
	/// <returns>buffer object</returns>
	int_buffer get_buffer();

};
#endif // !INT_SORTED
