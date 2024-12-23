#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>

int no5() {

    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    // Создаем список L
    std::list<int> L;
    int n;

    std::cout << "Введите количество элементов списка: ";
    std::cin >> n;
    if (n < 1) {
        std::cout << "Ошибка ввода.";
        return 0;
    }

    std::cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        L.push_back(element);
    }

    // Используем find для поиска первого нулевого элемента
    auto firstZero = std::find(L.begin(), L.end(), 0);

    if (firstZero != L.end()) {
        // Удаляем первый найденный нулевой элемент
        L.erase(firstZero);
    }

    // Используем rfind для поиска последнего нулевого элемента
    auto lastZeroReverse = std::find(L.rbegin(), L.rend(), 0);

    if (lastZeroReverse != L.rend()) {
        // Преобразуем обратный итератор в обычный и удаляем последний нулевой элемент
        L.erase(std::next(lastZeroReverse).base());
    }

    // Вывод списка после удаления элементов
    std::cout << "Список после удаления: ";
    for (const auto& elem : L) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
