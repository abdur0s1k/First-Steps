#include <iostream>
#include <fstream>
#include <cmath> // Для использования функции fabs
using namespace std;

int main() {
    setlocale(0, "");
    // Открываем файл для чтения
    ifstream file("f.txt");

    // Проверка успешности открытия файла
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }

    double value;
    double maxAbsoluteValue = 0.0; // Инициализируем максимальное значение модуля

    // Считываем компоненты из файла с нечётными номерами и находим максимальное значение модуля
    for (int i = 1; file >> value; ++i) {
        if (i % 2 != 0) { // Проверка на нечётность номера компоненты
            double absoluteValue = fabs(value);
            if (absoluteValue > maxAbsoluteValue) {
                maxAbsoluteValue = absoluteValue;
            }
        }
    }

    // Закрываем файл
    file.close();

    // Вывод результата
    cout << "Наибольшее значение модуля компонент с нечётными номерами: " << maxAbsoluteValue << std::endl;

    return 0;
}