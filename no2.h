#include <iostream>
#include <fstream>
#include <deque>
#include <iterator>
#include <string>
#include <locale>
#include <cstdlib>
using namespace std;

int no2()
{
	std::setlocale(LC_ALL, "Russian");
	std::wcout.imbue(std::locale("ru_RU.UTF-8"));

	int DequeSize;
	cout << "������� ������ ���� (������):";
	cin >> DequeSize;
	if (
		DequeSize % 2 != 0
		) {
		cout << "������ ���� ��������";
		return 0;
	}

	deque<int> myDeque;
	cout << "������� �������� ����: ";
	istream_iterator<int> inputIter(cin), endIter;
	copy_n(inputIter, DequeSize, back_inserter(myDeque));

	cout << "\n��������� ���: ";
	if (!myDeque.empty()) { // ���� ��� �� ����
		copy(myDeque.begin(), myDeque.end(), ostream_iterator<int>(cout, " ")); // ����� �� ����� ��������� ����
	}
	else {
		cout << "������ �����";
		return 0;
	}

	deque<int>::iterator i = myDeque.begin() + myDeque.size() / 2;
	for (size_t k = 0; k < DequeSize / 2; ++k) {
		// ��������� -1 ����� ������ ��������� ������ ��������
		i = myDeque.insert(myDeque.begin() + k * 2, -1);
	}

	// ����� ���� ����� ������� � �������� ������� � �������������� rbegin � rend
	cout << "��� ����� �������: ";
	for (deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
		cout << *it << " ";
	}
	cout << std::endl;


	return 0;
}