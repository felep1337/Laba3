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
	// ������ ��� Gnuplot
	const char* gnuplotScript = R"gnuplot(
        set xlabel "������ �������"
        set ylabel "����� (�������)"
        set title "��������� ������� ������ ����������"
        set key top right
        set style data linespoints
		set logscale x 10
    	set logscale y 10

        # ������ ������ �� �����
        plot "data.txt" using 1:2 with linespoints title "sort", \
             "data.txt" using 1:3 with linespoints title "merge", \
             "data.txt" using 1:4 with linespoints title "comb"
		pause -1
    )gnuplot";

	// ��������� ������ � ���� plot.gp
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
	vector<size_t> sizes = { 100, 200,400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400,3276800 }; // ������� ��������
	vector<double> times_std_sort;
	vector<double> times_merge;
	vector<double> times_comb;

	for (size_t size : sizes) {
		vector<int> vect;
		generation::Random(size, vect);

		// ������� ����� ������� ��� ������ ����������
		vector<int> vect_copy1 = vect;
		vector<int> vect_copy2 = vect;
		vector<int> vect_copy3 = vect;

		// �������� ����� ��� ������ ����������
		double time_std_sort = Timing::measureSortTime(Sorting::imsortfunc, vect_copy1);
		double time_merge = Timing::measureSortTime(Sorting::mergeSortWrapper, vect_copy2);
		double time_comb = Timing::measureSortTime(Sorting::combsort, vect_copy3);

		// ��������� ����������
		times_std_sort.push_back(time_std_sort);
		times_merge.push_back(time_merge);
		times_comb.push_back(time_comb);

		cout << "������: " << size << ", std::sort: " << time_std_sort
			<< ", merge: " << time_merge << ", comb: " << time_comb << endl;
	}

	// ���������� ������ � ����
	vector<vector<double>> data = { times_std_sort, times_merge, times_comb };
	writeDataToFile("data.txt", sizes, data);

	callGnuplot();//����� �� ��������������� �����

	cout << "��������� ��� ���������� ��������, ���������� ����!" << '\n'<< '\n' << "������ ��������� �������� : " << '\n' << "1. ������ ��������� ����� �������� N, ����� � ��������� N / 5" << '\n' << "2. ������������� ������ �������� N" << '\n' << "3. ������������� � �������� ������� �������� N" << '\n' << "4. ������������� ������ �������� N, � N / 10 �������������� ��� ��������� � ���������� ��������" << '\n';
	cout << '\n' << "�������� ������ ���������:";

	cin >> choice_first;

	cout << '\n' << "�������� ����� �������:";

	cin >> choice_second;

	cout << '\n' << "�������� ���������� �������" << '\n' << "1. ���������� ��������" << '\n' << "2. ���������� ���������" << '\n' << "3. ���������� ����� ���������� �������" << '\n'<< '\n' << "�������� ������ ����������:";

	cin >> choice_third;

	cout << '\n'<< "�������� ���������� �������� ����������:";

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
