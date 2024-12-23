#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>

int no4() {

    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::string name = "name2.txt";
    int N;

    std::cout << "Введите число N (1 <= N <= 26): ";
    std::cin >> N;

    // Проверка на корректность введенного числа
    if (N < 1 || N > 26) {
        std::cerr << "Ошибка: число N должно быть в диапазоне от 1 до 26." << std::endl;
        return 1;
    }

    // Открытие файла для записи
    std::ofstream outFile(name);
    if (!outFile) {
        std::cerr << "Ошибка: не удалось открыть файл для записи." << std::endl;
        return 1;
    }

    // Запись первых N прописных букв латинского алфавита в файл
    std::ostream_iterator<char> outputIter(outFile, "\n");
    char currentChar = 'A';
    std::generate_n(outputIter, N, [&currentChar]() { return currentChar++; });

    std::cout << "Данные успешно записаны в файл " << name << "." << std::endl;

    return 0;
}
