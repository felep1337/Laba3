#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <cstdlib>
#include <ctime> 

namespace generation {

	void Random(int n, std::vector<int>& vect) {
		srand(time(0));
		for (int i = 0; i < n; i++) {
			vect.push_back(rand() % n / 5);
		}
	}
	void Sorted(int n, std::vector<int>& vect) {
		for (int i = 0; i < n; i++) {
			vect.push_back(i);
		}
	}
	void Reversed(int n, std::vector<int>& vect) {
		for (int i = n; i > 0; i--) {
			vect.push_back(i);
		}
	}
	void Transposition(int n, std::vector<int>& vect) {
		for (int i = 0; i < n; i++) {
			vect.push_back(i);
		}
		for (int i = 0; i < (n / 10); i++) {
			std::swap(vect[rand()%n], vect[rand()%n]);
		}
	}
}

#endif