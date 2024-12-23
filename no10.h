#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <cstdlib>

int no10() {
    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));
    int n;
    std::cout << "������� ���������� ��������� �������: ";
    std::cin >> n; // ������ ���������� ���������
    if (n < 1) {
        std::cout << "������.";
        return 0;
    }

    std::vector<int> V(n); // ������� ������ ������� �������

    // ������ �������� �������
    std::cout << "������� " << n << " ��������� �������: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i]; // ������ ������ �������
    }

    // multimap ��� �������� ���������� �����������
    std::multimap<int, int> M;

    // ��������� multimap, ��������� �������� �� ��������� �����
    for (std::vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        int last_digit = *it % 10; // ��������� ����� ��������
        M.insert({ last_digit, *it });
    }

    // ����� ����������
    std::cout << "��������� �����������:" << std::endl;
    for (std::multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        std::cout << "����: " << it->first << " | ��������: " << it->second << std::endl;
    }

    return 0;
}