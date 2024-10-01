#include <iostream>
#include <cstdlib>
#include <ctime>
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
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    if (arr == nullptr) {
        cout << "Ошибка выделения памяти\n";
        return 1;
    }

    // Инициализация элементов массива псевдослучайными значениями
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 9 - 9;
        }
    }

    // Вывод элементов массива в виде таблицы
    cout << "Show massiv:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j];
            if (j != cols - 1) {
                cout << " | ";
            }
        }
        cout << endl;
    }

    // Вывод элементов массива в обратном порядке
    cout << "Show reverse massiv:\n";
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            cout << arr[i][j];
            if (j != 0) {
                cout << " | ";
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