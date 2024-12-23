#include <iostream>
#include <fstream>
#include <deque>
#include <iterator>
#include <string>
#include <locale>
#include <cstdlib>
#include "no.h"
#include "no2.h"
#include "no3.h"
#include "no4.h"
#include "no5.h"
#include "no6.h"
#include "n07.h"
#include "no8.h"
#include "no9.h"
#include "no10.h"
using namespace std;

int main()
{
	std::setlocale(LC_ALL, "Russian");
	std::wcout.imbue(std::locale("ru_RU.UTF-8"));
	
	int Choise;
	cout << "Введите номер задания:";
	while (!(std::cin >> Choise)) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Ошибка. Повторите ввод: ";
	}
	if (Choise == 1) {
		no1();
	}
	else if (Choise == 2)
	{
		no2();
	}
	else if (Choise == 3)
	{
		no3();
	}
	else if (Choise == 4)
	{
		no4();
	}
	else if (Choise == 5)
	{
		no5();
	}
	else if (Choise == 6)
	{
		no6();
	}
	else if (Choise == 7)
	{
		no7();
	}
	else if (Choise == 8)
	{
		no8();
	}
	else if (Choise == 9)
	{
		no9();
	}
	else if (Choise == 10)
	{
		no10();
	}
	else
	{
		std::cout << "Такого номера нет";
	}

	return 0;
}

