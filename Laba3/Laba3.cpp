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

	cout << "��������� ��� ���������� ��������" << '\n'<< '\n' << "������ ��������� �������� : " << '\n' << "1. ������ ��������� ����� �������� N, ����� � ��������� N / 5" << '\n' << "2. ������������� ������ �������� N" << '\n' << "3. ������������� � �������� ������� �������� N" << '\n' << "4. ������������� ������ �������� N, � N / 10 �������������� ��� ��������� � ���������� ��������" << '\n';
	cout << '\n' << "�������� ������ ���������:";

	cin >> choice_first;

	cout << '\n' << "�������� ����� �������:";

	cin >> choice_second;

	cout << '\n' << "�������� ���������� �������" << '\n' << "1. ���������� ���������" << '\n' << "2. ���������� ��������" << '\n' <<'\n' << "�������� ������ ����������:";

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
