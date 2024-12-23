#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>

int no4() {

    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::string name = "name2.txt";
    int N;

    std::cout << "������� ����� N (1 <= N <= 26): ";
    std::cin >> N;

    // �������� �� ������������ ���������� �����
    if (N < 1 || N > 26) {
        std::cerr << "������: ����� N ������ ���� � ��������� �� 1 �� 26." << std::endl;
        return 1;
    }

    // �������� ����� ��� ������
    std::ofstream outFile(name);
    if (!outFile) {
        std::cerr << "������: �� ������� ������� ���� ��� ������." << std::endl;
        return 1;
    }

    // ������ ������ N ��������� ���� ���������� �������� � ����
    std::ostream_iterator<char> outputIter(outFile, "\n");
    char currentChar = 'A';
    std::generate_n(outputIter, N, [&currentChar]() { return currentChar++; });

    std::cout << "������ ������� �������� � ���� " << name << "." << std::endl;

    return 0;
}
