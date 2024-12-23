#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string>
#include <locale>
#include <cstdlib>
using namespace std;

int no3()
{
    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    list<int> L1;
    list<int> L2;

    int L1Len;
    int L2Len;

    cout << "Введите количество элементов списка L1: ";
    cin >> L1Len;

    cout << "Введите " << L1Len << " элементов для списка L1: ";
    copy_n(istream_iterator<int>(cin), L1Len, back_inserter(L1));

    cout << "Введите количество элементов списка L2 (четный): ";
    cin >> L2Len;

    if (
        L2Len % 2 != 0
        ) {
        cout << "Размер списка нечетный";
        return 1;
    }

    cout << "Введите " << L2Len << " элементов для списка L2: ";
    copy_n(istream_iterator<int>(cin), L2Len, back_inserter(L2));

    // Находим итератор, указывающий на середину списка L2
    std::list<int>::iterator mid = std::next(L2.begin(), L2Len / 2);

    // Перемещаем первую половину списка L2 в начало списка L1
    L1.splice(L1.begin(), L2, L2.begin(), mid);

    // Вывод списка L1 с использованием итераторов
    std::cout << "Список L1 после splice: ";
    for (std::list<int>::iterator it = L1.begin(); it != L1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Вывод списка L2 с использованием итераторов
    std::cout << "Список L2 после splice: ";
    for (std::list<int>::iterator it = L2.begin(); it != L2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}