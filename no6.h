#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>

int no6() {
    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    // ������� ��� D
    std::deque<int> D;
    int N;

    std::cout << "������� ����� N (> 0): ";
    std::cin >> N;

    if (N <= 0) {
        std::cerr << "������: N ������ ���� ������ 0." << std::endl;
        return 1;
    }

    int totalElements;
    std::cout << "������� ����� ���������� ��������� ���� (�� ����� " << 2 * N << "): ";
    std::cin >> totalElements;

    if (totalElements < 2 * N) {
        std::cerr << "������: ���������� ��������� ���� ������ ���� �� ����� " << 2 * N << "." << std::endl;
        return 1;
    }

    std::cout << "������� " << totalElements << " ��������� ����: ";
    for (int i = 0; i < totalElements; ++i) {
        int element;
        std::cin >> element;
        D.push_back(element);
    }

    // ��������� ������ N ��������� ������������������� 1, 2, ..., N
    auto forwardIt = D.begin();
    int currentNumber = 1;
    std::generate(forwardIt, forwardIt + N, [&currentNumber]() { return currentNumber++; });

    // ��������� ��������� N ��������� ������������������� N, N-1, ..., 1
    auto reverseIt = D.end() - N; // ��������� �� ������ ��������� N ���������
    currentNumber = N;
    std::generate(reverseIt, D.end(), [&currentNumber]() { return currentNumber--; });

    // ����� ���� ����� ���������
    std::cout << "��� ����� ����������: ";
    for (const auto& elem : D) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}