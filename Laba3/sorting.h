#ifndef SORTING_H
#define SORTING_H

#include <vector>

namespace Sorting {
	void combsort(std::vector<int>  &vect);
	void merge(std::vector<int> &vect, size_t left_index, size_t new_index, size_t right_index);
	void mergeSort(std::vector<int> &vect, size_t left_index, size_t right_index);
	void mergeSortWrapper(std::vector<int>& vect);
	void imsortfunc(std::vector<int>& vect);
}

#endif
