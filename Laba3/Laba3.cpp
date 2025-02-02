#include <iostream>
#include <chrono>
#include "sorting.h"
#include "generation.h"
#include "timing.h"

using namespace std;

int main() {
	
	setlocale(LC_ALL, "Russian");

	vector <int> vect;
	int choice_first;
	int choice_second;
	int choice_third;
	int choice_fourth;

	cout << "Программа для сортировки массивов" << '\n'<< '\n' << "Способ генерации массивов : " << '\n' << "1. Массив случайные чисел размером N, числа в диапозоне N / 5" << '\n' << "2. Упорядоченный массив размером N" << '\n' << "3. Упорядоченный в обратном порядке размером N" << '\n' << "4. Упорядоченный массив размером N, с N / 10 перестановками пар элементов с случайными номерами" << '\n';
	cout << '\n' << "Выберете способ генерации:";

	cin >> choice_first;

	cout << '\n' << "Выберите длину массива:";

	cin >> choice_second;

	cout << '\n' << "Варианты сортировки массива" << '\n' << "1. Сортировка расчёской" << '\n' << "2. Сортировка слиянием" << '\n' <<'\n' << "Выберите способ сортировки:";

	cin >> choice_third;

	cout << '\n'<< "Выберите количество повторов сортировки:";

	cin >> choice_fourth;

	switch (choice_first) {
	case 1:
		Timing::Timing_function(choice_third, choice_second, choice_fourth, generation::Random, vect);
		break;
	case 2:
		Timing::Timing_function(choice_third, choice_second, choice_fourth, generation::Sorted, vect);
		break;
	case 3:
		Timing::Timing_function(choice_third, choice_second, choice_fourth, generation::Reversed, vect);
		break;
	case 4:
		Timing::Timing_function(choice_third, choice_second, choice_fourth, generation::Transposition, vect);
		break;
	}

	return 0;
}
