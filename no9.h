#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>

int no9() {

    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));
    // ���� V0
    std::cout << "������� ������ ������� V0: ";
    int size_V0;
    std::cin >> size_V0;
    if (size_V0 < 1) {
        std::cout << "������ �����.";
        return 0;
    }

    std::cout << "������� �������� ������� V0: ";
    std::vector<int> V0(size_V0);
    for (int i = 0; i < size_V0; ++i) {
        std::cin >> V0[i];
    }

    // ����������� V0 � multiset
    std::multiset<int> multiset_V0(V0.begin(), V0.end());

    // ���� ���������� �������� N
    std::cout << "������� ���������� �������� N: ";
    int N;
    std::cin >> N;
    if (N < 1) {
        std::cout << "������ �����.";
        return 0;
    }

    // ������� ���������� ��������
    int count = 0;

    // ��������� ������� �������
    for (int i = 0; i < N; ++i) {
        std::cout << "������� ������ ������� V" << i + 1 << ": ";
        int size_VI;
        std::cin >> size_VI;
        if (size_VI < 1) {
            std::cout << "������ �����.";
            return 0;
        }

        if (size_V0 > size_VI) {
            std::cout << "������ ������ ������� V0";
            return 0;
        }

        std::cout << "������� �������� ������� V" << i + 1 << ": ";
        std::vector<int> VI(size_VI);
        for (int j = 0; j < size_VI; ++j) {
            std::cin >> VI[j];
        }

        // ����������� VI � multiset
        std::multiset<int> multiset_VI(VI.begin(), VI.end());

        // ���������, ���������� �� V0 � ������� ������� VI
        if (std::includes(multiset_VI.begin(), multiset_VI.end(),
            multiset_V0.begin(), multiset_V0.end())) {
            ++count; // ����������� �������
        }
    }

    // ����� ����������
    std::cout << "���������� ���������� ��������: " << count << std::endl;

    return 0;
}