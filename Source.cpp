#include <iostream>
#include <chrono>
#include <algorithm>
#include "int_buffer.h"
#include "int_sorted.h"
void time_selection_sort(int* arr, const int size);
void time_regular_merge(int* arr, const int size);
void time_std_sort(int* arr, const int size);
void compare_times(int* arr, const int size);
void f(int_buffer buf) {
	int count = 1;
	for (auto e : buf) {
		e = count;
		count++;
		std::cout << e << "\n";
	}
	/*for (int* i = buf.begin(); i != buf.end(); i++) {
		*i = count;
		count++;
	}
	for (const int* i = buf.begin(); i != buf.end(); i++) {
		std::cout << *i << "\n";
	}*/
}
int main() {
	const int size = 100000;
	int tmp[size]{};
	for (int i = 0; i < size; i++) {
		tmp[i] = rand();
	}
	compare_times(tmp, size);
	return 0;
}
void time_selection_sort(int* arr, const int size) {
	int_buffer selection = int_buffer(arr, size);
	auto selection_start = std::chrono::steady_clock::now();
	selection.selection_sort(selection);
	auto selection_end = std::chrono::steady_clock::now();
	auto selection_total = std::chrono::duration_cast<std::chrono::milliseconds>(selection_end - selection_start);
	std::cout << "Time taken for selection sort on " << size << " elements: " << selection_total.count() << std::endl;
}
void time_regular_merge(int* arr, const int size) {
	auto merge_start = std::chrono::steady_clock::now();
	auto sorted = int_sorted(arr, size);
	auto merge_end = std::chrono::steady_clock::now();
	auto merge_total = std::chrono::duration_cast<std::chrono::milliseconds>(merge_end - merge_start);
	std::cout << "Time taken for merge on " << size << " elements: " << merge_total.count() << std::endl;
}
void time_std_sort(int* arr, const int size) {
	auto std_sort_start = std::chrono::steady_clock::now();
	std::sort(arr, arr + size);
	auto std_sort_end = std::chrono::steady_clock::now();
	auto std_sort_total = std::chrono::duration_cast<std::chrono::milliseconds>(std_sort_end - std_sort_start);
	std::cout << "Time taken for std::sort on " << size << " elements: " << std_sort_total.count() << std::endl;
}
void compare_times(int* arr, const int size) {
	//time_selection_sort(arr, size);
	time_regular_merge(arr, size);
	auto test = int_buffer(arr, size);
	std::cout << "Sorted before: " << test.is_sorted() << std::endl;
	time_std_sort(arr, size);
	test = int_buffer(arr, size);
	std::cout << "Sorted after: " << test.is_sorted() << std::endl;
	
}