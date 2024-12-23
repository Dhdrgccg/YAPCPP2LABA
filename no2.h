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
	cout << "Введите размер дека (четный):";
	cin >> DequeSize;
	if (
		DequeSize % 2 != 0
		) {
		cout << "Размер дека нечетный";
		return 0;
	}

	deque<int> myDeque;
	cout << "Введите элементы дека: ";
	istream_iterator<int> inputIter(cin), endIter;
	copy_n(inputIter, DequeSize, back_inserter(myDeque));

	cout << "\nВведенный дек: ";
	if (!myDeque.empty()) { // если дек не пуст
		copy(myDeque.begin(), myDeque.end(), ostream_iterator<int>(cout, " ")); // вывод на экран элементов дека
	}
	else {
		cout << "Ошибка ввода";
		return 0;
	}

	deque<int>::iterator i = myDeque.begin() + myDeque.size() / 2;
	for (size_t k = 0; k < DequeSize / 2; ++k) {
		// Вставляем -1 перед каждым элементом первой половины
		i = myDeque.insert(myDeque.begin() + k * 2, -1);
	}

	// Вывод дека после вставки в обратном порядке с использованием rbegin и rend
	cout << "Дек после вставки: ";
	for (deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
		cout << *it << " ";
	}
	cout << std::endl;


	return 0;
}