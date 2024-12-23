#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

// ������� ��� ������ �������
void printVector(const std::vector<int>& v) {
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int no7() {
    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));
    // ���� ������
    int n;
    std::cout << "������� ���������� ��������� ������� (������ 3): ";
    std::cin >> n;

    if (n % 3 != 0) {
        std::cerr << "������: ���������� ��������� ������ ���� ������ 3." << std::endl;
        return 1;
    }

    std::vector<int> V(n);
    std::cout << "������� �������� �������: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    std::cout << "����������� ������: ";
    printVector(V);

    // ��������������� ���������
    // 1-� ����� stable_partition: ���������� ������������� � ������
    auto zeroStart = std::stable_partition(V.begin(), V.end(), [](int x) {
        return x < 0; // ������� ��� ������������� �����
        });

    // 2-� ����� stable_partition: ���������� ���� ����� �������������
    std::stable_partition(zeroStart, V.end(), [](int x) {
        return x == 0; // ������� ��� �����
        });

    // ����� ����������
    std::cout << "������������������ ������: ";
    printVector(V);

    return 0;
}
