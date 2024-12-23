#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>

int no6() {
    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    // Создаем дек D
    std::deque<int> D;
    int N;

    std::cout << "Введите число N (> 0): ";
    std::cin >> N;

    if (N <= 0) {
        std::cerr << "Ошибка: N должно быть больше 0." << std::endl;
        return 1;
    }

    int totalElements;
    std::cout << "Введите общее количество элементов дека (не менее " << 2 * N << "): ";
    std::cin >> totalElements;

    if (totalElements < 2 * N) {
        std::cerr << "Ошибка: количество элементов дека должно быть не менее " << 2 * N << "." << std::endl;
        return 1;
    }

    std::cout << "Введите " << totalElements << " элементов дека: ";
    for (int i = 0; i < totalElements; ++i) {
        int element;
        std::cin >> element;
        D.push_back(element);
    }

    // Заполняем первые N элементов последовательностью 1, 2, ..., N
    auto forwardIt = D.begin();
    int currentNumber = 1;
    std::generate(forwardIt, forwardIt + N, [&currentNumber]() { return currentNumber++; });

    // Заполняем последние N элементов последовательностью N, N-1, ..., 1
    auto reverseIt = D.end() - N; // Указываем на начало последних N элементов
    currentNumber = N;
    std::generate(reverseIt, D.end(), [&currentNumber]() { return currentNumber--; });

    // Вывод дека после изменений
    std::cout << "Дек после заполнения: ";
    for (const auto& elem : D) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}