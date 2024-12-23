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

    // ��� ����� � �������
    std::string filename = "name.txt";

    // �������� ����� ��� ������
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "�� ������� ������� ����: " << filename << std::endl;
        return 1;
    }

    // ������� ������ � ��������� ��� ������� �� ����� � �������������� ����������
    std::vector<int> V((std::istream_iterator<int>(inputFile)), std::istream_iterator<int>());

    // ��������� ����
    inputFile.close();

    // ����� ��������� ������� � �������� ������� � �������������� ����������
    std::cout << "�������� ������� � �������� �������:" << std::endl;
    for (std::vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
