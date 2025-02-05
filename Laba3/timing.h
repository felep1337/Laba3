#ifndef TIMING_H
#define TIMING_H
#include <chrono>
#include <vector>
#include <functional>

namespace Timing {

	void Timing_function(int S, int N, int K, std::function<void(int, std::vector<int>& vect)> generat, std::vector<int>& vect);
	template <typename SortFunction>
	double measureSortTime(SortFunction sortFunc, std::vector<int>& vec) {
		auto start = std::chrono::high_resolution_clock::now();
		sortFunc(vec);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		return duration.count(); // Возвращает время в секундах
	}
}

#endif
