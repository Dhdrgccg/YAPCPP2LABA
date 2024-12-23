#include <iostream>
#include <deque>
#include <list>
#include <string>

int no8() {
    // Исходный список
    std::list<std::string> L = { "ABC", "DEF", "KLM", "XYZ" };

    // Дек для хранения результата
    std::deque<std::string> D;

    // Итерируемся по парам соседних элементов
    auto it1 = L.begin();
    auto it2 = std::next(L.begin());
    while (it2 != L.end()) {
        if (!it1->empty() && !it2->empty()) {
            // Формируем строку из первой буквы левого и последней буквы правого
            std::string result(1, it1->front());
            result += it2->back();
            D.push_back(result);
        }
        ++it1;
        ++it2;
    }

    // Вывод результата
    for (const auto& str : D) {
        std::cout << str << " ";
    }

    return 0;
}
