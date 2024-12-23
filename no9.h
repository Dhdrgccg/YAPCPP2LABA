#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>

int no9() {

    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));
    // Ввод V0
    std::cout << "Введите размер вектора V0: ";
    int size_V0;
    std::cin >> size_V0;
    if (size_V0 < 1) {
        std::cout << "Ошибка ввода.";
        return 0;
    }

    std::cout << "Введите элементы вектора V0: ";
    std::vector<int> V0(size_V0);
    for (int i = 0; i < size_V0; ++i) {
        std::cin >> V0[i];
    }

    // Преобразуем V0 в multiset
    std::multiset<int> multiset_V0(V0.begin(), V0.end());

    // Ввод количества векторов N
    std::cout << "Введите количество векторов N: ";
    int N;
    std::cin >> N;
    if (N < 1) {
        std::cout << "Ошибка ввода.";
        return 0;
    }

    // Счетчик подходящих векторов
    int count = 0;

    // Обработка каждого вектора
    for (int i = 0; i < N; ++i) {
        std::cout << "Введите размер вектора V" << i + 1 << ": ";
        int size_VI;
        std::cin >> size_VI;
        if (size_VI < 1) {
            std::cout << "Ошибка ввода.";
            return 0;
        }

        if (size_V0 > size_VI) {
            std::cout << "Вектор меньше Вектора V0";
            return 0;
        }

        std::cout << "Введите элементы вектора V" << i + 1 << ": ";
        std::vector<int> VI(size_VI);
        for (int j = 0; j < size_VI; ++j) {
            std::cin >> VI[j];
        }

        // Преобразуем VI в multiset
        std::multiset<int> multiset_VI(VI.begin(), VI.end());

        // Проверяем, содержится ли V0 в текущем векторе VI
        if (std::includes(multiset_VI.begin(), multiset_VI.end(),
            multiset_V0.begin(), multiset_V0.end())) {
            ++count; // Увеличиваем счетчик
        }
    }

    // Вывод результата
    std::cout << "Количество подходящих векторов: " << count << std::endl;

    return 0;
}