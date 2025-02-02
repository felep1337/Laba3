#ifndef SORTING_H
#define SORTING_H

#include <vector>

namespace Sorting {
	std::vector<int> combsort(std::vector<int>  &vect);
	void merge(std::vector<int> &vect, int left_index, int new_index, int right_index);
	void mergeSort(std::vector<int> &vect, int left_index, int right_index);
}

#endif
