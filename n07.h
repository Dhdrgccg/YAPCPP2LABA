#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

// Функция для вывода вектора
void printVector(const std::vector<int>& v) {
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int no7() {
    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));
    // Ввод данных
    int n;
    std::cout << "Введите количество элементов вектора (кратно 3): ";
    std::cin >> n;

    if (n % 3 != 0) {
        std::cerr << "Ошибка: количество элементов должно быть кратно 3." << std::endl;
        return 1;
    }

    std::vector<int> V(n);
    std::cout << "Введите элементы вектора: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    std::cout << "Изначальный вектор: ";
    printVector(V);

    // Перегруппировка элементов
    // 1-й вызов stable_partition: перемещаем отрицательные в начало
    auto zeroStart = std::stable_partition(V.begin(), V.end(), [](int x) {
        return x < 0; // Условие для отрицательных чисел
        });

    // 2-й вызов stable_partition: перемещаем нули после отрицательных
    std::stable_partition(zeroStart, V.end(), [](int x) {
        return x == 0; // Условие для нулей
        });

    // Вывод результата
    std::cout << "Перегруппированный вектор: ";
    printVector(V);

    return 0;
}
