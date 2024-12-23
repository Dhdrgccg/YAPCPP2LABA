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

    cout << "������� ���������� ��������� ������ L1: ";
    cin >> L1Len;

    cout << "������� " << L1Len << " ��������� ��� ������ L1: ";
    copy_n(istream_iterator<int>(cin), L1Len, back_inserter(L1));

    cout << "������� ���������� ��������� ������ L2 (������): ";
    cin >> L2Len;

    if (
        L2Len % 2 != 0
        ) {
        cout << "������ ������ ��������";
        return 1;
    }

    cout << "������� " << L2Len << " ��������� ��� ������ L2: ";
    copy_n(istream_iterator<int>(cin), L2Len, back_inserter(L2));

    // ������� ��������, ����������� �� �������� ������ L2
    std::list<int>::iterator mid = std::next(L2.begin(), L2Len / 2);

    // ���������� ������ �������� ������ L2 � ������ ������ L1
    L1.splice(L1.begin(), L2, L2.begin(), mid);

    // ����� ������ L1 � �������������� ����������
    std::cout << "������ L1 ����� splice: ";
    for (std::list<int>::iterator it = L1.begin(); it != L1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // ����� ������ L2 � �������������� ����������
    std::cout << "������ L2 ����� splice: ";
    for (std::list<int>::iterator it = L2.begin(); it != L2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}