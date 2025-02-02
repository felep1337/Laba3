#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <cstdlib>
#include <ctime> 

namespace generation {
	
	void Random(int n, std::vector<int>& vect);
	void Sorted(int n, std::vector<int>& vect);
	void Reversed(int n, std::vector<int>& vect);
	void Transposition(int n, std::vector<int>& vect);
}

#endif