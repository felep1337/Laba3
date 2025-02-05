#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <cstdlib>
#include <ctime> 

namespace generation {
	
	void Random(size_t n, std::vector<int>& vect);
	void Sorted(size_t n, std::vector<int>& vect);
	void Reversed(size_t n, std::vector<int>& vect);
	void Transposition(size_t n, std::vector<int>& vect);
}

#endif