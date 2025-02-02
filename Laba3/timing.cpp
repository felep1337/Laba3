#include "timing.h"
#include "sorting.h"
#include "generation.h"
#include <iostream>
#include <chrono>
#include <functional>

using namespace std;
using Time = chrono::time_point<chrono::steady_clock>;
using Diff = chrono::milliseconds;

namespace Timing {

	void Timing_function(int S, int N, int K,function<void(int,vector<int> &vect)> generat, vector<int> &vect) {

		generat(N, vect);
		vector<int> tempvect = vect;

		switch (S) {
		case 1: {
			Time t1 = chrono::steady_clock::now();

			for (int i = 0; i < K; i++) {
				Sorting::mergeSort(vect, 0, vect.size() - 1);
				vect = tempvect;
			}
			Time t2 = chrono::steady_clock::now();
			Diff diff = chrono::duration_cast<Diff>(t2 - t1);
			cout << '\n' << "-------------------" << '\n' << "Ваш массив отсортирован за " << diff.count() << " мс" << endl;
			break;
		}
		case 2: {
			Time t1 = chrono::steady_clock::now();

			for (int i = 0; i < K; i++) {
				Sorting::combsort(vect);
				vect = tempvect;
			}
			Time t2 = chrono::steady_clock::now();
			Diff diff = chrono::duration_cast<Diff>(t2 - t1);
			cout << '\n' << "-------------------" << '\n' << "Ваш массив отсортирован за " << diff.count() << " мс" << endl;
			break;
		}
		}
	}
}