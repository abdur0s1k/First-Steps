#include <iostream>
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

    // Ввод элементов массива
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Вывод элементов массива в виде таблицы
    cout << "Print array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j];
            if (j != cols - 1) {
                cout << " ; ";
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
