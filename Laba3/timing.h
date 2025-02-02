#ifndef TIMING_H
#define TIMING_H
#include <chrono>
#include <vector>
#include <functional>

namespace Timing {

	void Timing_function(int S, int N, int K, std::function<void(int, std::vector<int>& vect)> generat, std::vector<int>& vect);

}

#endif
