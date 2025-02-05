#include <iostream>
#include <chrono>
#include "sorting.h"
#include "generation.h"
#include "timing.h"
#include <fstream>
#include <string>

using namespace std;

void writeDataToFile(const std::string& filename, const std::vector<size_t>& sizes,const std::vector<std::vector<double>>& data) {
	std::ofstream file(filename);

	for (size_t i = 0; i < data[0].size(); ++i) {
		file << sizes[i]<< " " << data[0][i] << " " << data[1][i] << " " << data[2][i] << "\n";
	}
	file.close();
}

void callGnuplot() {
	// Скрипт для Gnuplot
	const char* gnuplotScript = R"gnuplot(
        set xlabel "Размер массива"
        set ylabel "Время (секунды)"
        set title "Сравнение времени работы сортировок"
        set key top right
        set style data linespoints
		set logscale x 10
    	set logscale y 10

        # Чтение данных из файла
        plot "data.txt" using 1:2 with linespoints title "sort", \
             "data.txt" using 1:3 with linespoints title "merge", \
             "data.txt" using 1:4 with linespoints title "comb"
		pause -1
    )gnuplot";

	// Сохраняем скрипт в файл plot.gp
	std::ofstream gnuplotFile("plot.plt");
	gnuplotFile << gnuplotScript;
	gnuplotFile.close();

	system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" plot.plt");
}

int main() {

	setlocale(LC_ALL, "Russian");

	int choice_first;
	int choice_second;
	int choice_third;
	int choice_fourth;
	vector <int> vect;
	vector<size_t> sizes = { 100, 200,400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400,3276800 }; // Размеры массивов
	vector<double> times_std_sort;
	vector<double> times_merge;
	vector<double> times_comb;

	for (size_t size : sizes) {
		vector<int> vect;
		generation::Random(size, vect);

		// Создаем копии вектора для каждой сортировки
		vector<int> vect_copy1 = vect;
		vector<int> vect_copy2 = vect;
		vector<int> vect_copy3 = vect;

		// Измеряем время для каждой сортировки
		double time_std_sort = Timing::measureSortTime(Sorting::imsortfunc, vect_copy1);
		double time_merge = Timing::measureSortTime(Sorting::mergeSortWrapper, vect_copy2);
		double time_comb = Timing::measureSortTime(Sorting::combsort, vect_copy3);

		// Сохраняем результаты
		times_std_sort.push_back(time_std_sort);
		times_merge.push_back(time_merge);
		times_comb.push_back(time_comb);

		cout << "Размер: " << size << ", std::sort: " << time_std_sort
			<< ", merge: " << time_merge << ", comb: " << time_comb << endl;
	}

	// Записываем данные в файл
	vector<vector<double>> data = { times_std_sort, times_merge, times_comb };
	writeDataToFile("data.txt", sizes, data);

	callGnuplot();//Вывод на логарифмической шкале

	cout << "Программа для сортировки массивов, отсортируй свой!" << '\n'<< '\n' << "Способ генерации массивов : " << '\n' << "1. Массив случайные чисел размером N, числа в диапозоне N / 5" << '\n' << "2. Упорядоченный массив размером N" << '\n' << "3. Упорядоченный в обратном порядке размером N" << '\n' << "4. Упорядоченный массив размером N, с N / 10 перестановками пар элементов с случайными номерами" << '\n';
	cout << '\n' << "Выберете способ генерации:";

	cin >> choice_first;

	cout << '\n' << "Выберите длину массива:";

	cin >> choice_second;

	cout << '\n' << "Варианты сортировки массива" << '\n' << "1. Сортировка слиянием" << '\n' << "2. Сортировка расчёской" << '\n' << "3. Сортировка через встроенную функцию" << '\n'<< '\n' << "Выберите способ сортировки:";

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
