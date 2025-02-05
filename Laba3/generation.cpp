#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <cstdlib>
#include <ctime> 

namespace generation {

	void Random(size_t n, std::vector<int>& vect) {
		srand(static_cast<unsigned int>(time(0)));
		for (size_t i = 0; i < n; i++) {
			vect.push_back(rand() % n / 5);
		}
	}
	void Sorted(size_t n, std::vector<int>& vect) {
		for (int i = 0; i < n; i++) {
			vect.push_back(i);
		}
	}
	void Reversed(size_t n, std::vector<int>& vect) {
		for (int i = static_cast<int>(n); i > 0; i--) {
			vect.push_back(i);
		}
	}
	void Transposition(size_t n, std::vector<int>& vect) {
		for (int i = 0; i < n; i++) {
			vect.push_back(i);
		}
		for (int i = 0; i < (n / 10); i++) {
			std::swap(vect[rand()%n], vect[rand()%n]);
		}
	}
}

#endif