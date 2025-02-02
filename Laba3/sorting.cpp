#include "sorting.h"

using namespace std;

namespace Sorting {
	vector<int> combsort(vector<int>& vect) {
		int n = (int)vect.size();
		int step = n - 1;
		double reduction_factor = 1.25;
		while (step > 1) {
			step = (int)(step / reduction_factor);
			for (int i = 0; i + step < n; i++) {
				if (vect[i] > vect[i + step]) {
					swap(vect[i], vect[i + step]);
				}
			}
		}
		return vect;
	}
	void merge(vector<int>& vect, int left_index, int new_index, int right_index) {

		int lenght_first = new_index - left_index + 1;
		int lenght_second = right_index - new_index;

		vector<int> temp_vect1(lenght_first);
		vector<int> temp_vect2(lenght_second);

		for (int i = 0; i < lenght_first; i++) {
			temp_vect1[i] = vect[left_index + i];
		}
		for (int i = 0; i < lenght_second; i++) {
			temp_vect2[i] = vect[new_index + i + 1];
		}

		int index_first = 0;
		int index_second = 0;
		int index_vect = left_index;

		while (index_first < lenght_first && index_second < lenght_second) {
			if (temp_vect1[index_first] <= temp_vect2[index_second]) {
				vect[index_vect] = temp_vect1[index_first];
				index_first++;
			}
			else {
				vect[index_vect] = temp_vect2[index_second];
				index_second++;
			}
			index_vect++;
		}
		while (index_first < lenght_first) {
			vect[index_vect] = temp_vect1[index_first];
			index_first++;
			index_vect++;
		}
		while (index_second < lenght_second) {
			vect[index_vect] = temp_vect2[index_second];
			index_second++;
			index_vect++;
		}
	}
	void mergeSort(vector<int>& vect, int left_index, int right_index) {
		if (left_index < right_index) {
			int new_index = left_index + (right_index - left_index) / 2;
			mergeSort(vect, left_index, new_index);
			mergeSort(vect, new_index + 1, right_index);

			merge(vect, left_index, new_index, right_index);
		}
	}
}