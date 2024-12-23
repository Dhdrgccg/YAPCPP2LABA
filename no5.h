#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>

int no5() {

    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    // ������� ������ L
    std::list<int> L;
    int n;

    std::cout << "������� ���������� ��������� ������: ";
    std::cin >> n;
    if (n < 1) {
        std::cout << "������ �����.";
        return 0;
    }

    std::cout << "������� " << n << " ���������: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        L.push_back(element);
    }

    // ���������� find ��� ������ ������� �������� ��������
    auto firstZero = std::find(L.begin(), L.end(), 0);

    if (firstZero != L.end()) {
        // ������� ������ ��������� ������� �������
        L.erase(firstZero);
    }

    // ���������� rfind ��� ������ ���������� �������� ��������
    auto lastZeroReverse = std::find(L.rbegin(), L.rend(), 0);

    if (lastZeroReverse != L.rend()) {
        // ����������� �������� �������� � ������� � ������� ��������� ������� �������
        L.erase(std::next(lastZeroReverse).base());
    }

    // ����� ������ ����� �������� ���������
    std::cout << "������ ����� ��������: ";
    for (const auto& elem : L) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
