#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    int rows, cols;
    setlocale(0, "");

    // Ввод количества строк
    do {
        cout << "Введите количество строк: ";
        cin >> rows;
        if (rows <= 0) {
            cout << "Количество строк должно быть положительным числом\n";
        }
    } while (rows <= 0);

    // Ввод количества столбцов
    do {
        cout << "Введите количество столбцов: ";
        cin >> cols;
        if (cols <= 0) {
            cout << "Количество столбцов должно быть положительным числом\n";
        }
    } while (cols <= 0);

    // Выделение динамической памяти
    double** arr = new double* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[cols];
    }

    if (arr == nullptr) {
        cout << "Ошибка выделения памяти\n";
        return 1;
    }

    // Инициализация элементов массива рандомными значениями
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (rand() % 1000) / 10.0; // Рандомное значение от 0 до 100 с точностью до десятых
        }
    }

    // Вывод элементов массива в виде таблицы
    cout << "Print massiv:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j];
            if (j != cols - 1) {
                cout << " | ";
            }
        }
        cout << endl;
    }

    // Вывод нового вида массива
    cout << "New vision of array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > 2) {
                cout << arr[i][j];
                if (j != cols - 1) {
                    cout << " | ";
                }
            }
        }
        cout << endl;
    }

    // Освобождение динамической памяти
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}