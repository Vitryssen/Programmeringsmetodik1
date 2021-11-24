#pragma once
#ifndef INT_BUFFER
#define INT_BUFFER
class int_buffer {
	private:
		int bufferSize;
		int* valuePtr;
		void swap(int_buffer& buffer);
	public:
		/// <summary>
		///	Creates an int buffer with the given size
		/// </summary>
		/// <param name="size">Size of buffer</param>
		explicit int_buffer(size_t size); // size_t
		/// <summary>
		/// Creates a int buffer with given size and fills it with given int values
		/// </summary>
		/// <param name="source">Given int values to fill buffer with</param>
		/// <param name="size">Given size for the buffer</param>
		int_buffer(const int* source, size_t size);
		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="rhs">Int buffer to make a copy of</param>
		int_buffer(const int_buffer& rhs);
		/// <summary>
		/// Move constructor
		/// </summary>
		/// <param name="rhs">Given buffer to move</param>
		int_buffer(int_buffer&& rhs) noexcept;
		/// <summary>
		/// Copy assignment for int buffers
		/// </summary>
		/// <param name="rhs">Buffer to copy</param>
		/// <returns>Copy of given buffer</returns>
		int_buffer& operator =(const int_buffer& rhs) noexcept;
		/// <summary>
		/// Assigns int buffer by moving
		/// </summary>
		/// <param name="rhs">Int buffer to move</param>
		/// <returns>Moved buffer used to assign</returns>
		int_buffer& operator =(int_buffer&& rhs) noexcept;
		/// <summary>
		///	Access value at the given index
		/// </summary>
		/// <param name="index">index of value</param>
		/// <returns>value at given index</returns>
		int& operator [](size_t index);
		/// <summary>
		///	Access value at the given index
		/// </summary>
		/// <param name="index">const index of value</param>
		/// <returns>const value at given index</returns>
		const int& operator [](size_t index) const;
		/// <summary>
		/// Returns const size of the int buffer
		/// </summary>
		/// <returns>const value of size</returns>
		size_t size() const;
		/// <summary>
		/// Returns int pointer to start of buffer
		/// </summary>
		/// <returns>int pointing to start of buffer</returns>
		int* begin();
		/// <summary>
		/// Returns int pointer to end of buffer
		/// </summary>
		/// <returns>int pointing to end of buffer</returns>
		int* end();
		/// <summary>
		/// Returns const int pointer to start of buffer
		/// </summary>
		/// <returns>const int pointing to start of buffer</returns>
		const int* begin() const;
		/// <summary>
		/// Returns const int pointer to end of buffer
		/// </summary>
		/// <returns>const int pointing to end of buffer</returns>
		const int* end() const;
		/// <summary>
		/// sort the buffer by using selection sort
		/// </summary>
		/// <param name="source">buffer to sort</param>
		/// <returns>sorted buffer</returns>
		int_buffer static selection_sort(int_buffer source);
		/// <summary>
		/// Checks if buffer is sorted
		/// </summary>
		/// <returns>1 or 0 if its sorted or not</returns>
		bool is_sorted();
		/// <summary>
		/// Deconstructs the int buffer
		/// </summary>
		~int_buffer();
};
#endif