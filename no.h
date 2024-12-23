#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <locale>
#include <cstdlib>


int no1() {
    std::setlocale(LC_ALL, "Russian");
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    // Имя файла с данными
    std::string filename = "name.txt";

    // Открытие файла для чтения
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return 1;
    }

    // Создаем вектор и заполняем его числами из файла с использованием итераторов
    std::vector<int> V((std::istream_iterator<int>(inputFile)), std::istream_iterator<int>());

    // Закрываем файл
    inputFile.close();

    // Вывод элементов вектора в исходном порядке с использованием итераторов
    std::cout << "Элементы вектора в исходном порядке:" << std::endl;
    for (std::vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
