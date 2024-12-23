#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <cstdlib>

int no10() {
    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));
    int n;
    std::cout << "Введите количество элементов вектора: ";
    std::cin >> n; // Вводим количество элементов
    if (n < 1) {
        std::cout << "Ошибка.";
        return 0;
    }

    std::vector<int> V(n); // Создаем вектор нужного размера

    // Вводим элементы вектора
    std::cout << "Введите " << n << " элементов вектора: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i]; // Вводим каждый элемент
    }

    // multimap для хранения результата группировки
    std::multimap<int, int> M;

    // Заполняем multimap, группируя элементы по последней цифре
    for (std::vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        int last_digit = *it % 10; // Последняя цифра элемента
        M.insert({ last_digit, *it });
    }

    // Вывод результата
    std::cout << "Результат группировки:" << std::endl;
    for (std::multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        std::cout << "Ключ: " << it->first << " | Значение: " << it->second << std::endl;
    }

    return 0;
}