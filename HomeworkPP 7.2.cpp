#include <iostream>
#include <Windows.h>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 0;
    auto begin = [](int& size) {
        bool true_false = true;
        std::cout << "Введите количество элементов: ";
        do {
            if ((std::cin >> size).good()) {
                std::vector<int> vec(size, 0);
                return vec;
            }
            if (std::cin.fail()) {
                std::cin.clear();
                std::cout << "Неверный ввод, повторите.\n";
            }
        } while (true_false);
    };
    std::vector<int> vec = begin(size);
    bool true_false = true;
    std::cout << "Введите элементы: " << std::endl;
    for (int i = 0; i < size; ++i) {
        do {
            std::cout << i + 1 << ": ";
            if ((std::cin >> vec[i]).good()) { true_false = false; }
            if (std::cin.fail()) {
                std::cin.clear();
                std::cout << "Неверный ввод, повторите.\n";
            }
        } while (true_false);
    }
    std::set<int> sets;
    std::cout << "\n[IN]:" << std::endl;
    for (const auto& elem : vec) {
        std::cout << elem << std::endl;
        sets.insert(elem);
    }
    std::cout << "\n[OUT]:" << std::endl;
    auto output = [](const auto& elem) {
        std::cout << elem << std::endl;
    };
    std::for_each(sets.rbegin(), sets.rend(), output);
    system("pause");
    return 0;
}
