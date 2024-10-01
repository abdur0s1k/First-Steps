#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    do {
        cout << "Enter the number of rows: ";
        cin >> rows;
    } while (rows <= 0);

    do {
        cout << "Enter the number of columns: ";
        cin >> cols;
    } while (cols <= 0);

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    if (arr == nullptr) {
        cout << "Memory allocation failed. Exiting program." << endl;
        return 1;
    }

    int value = -950;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value;
            value += 25;
        }
    }

    cout << "Print massiv:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Print new massiv:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] *= 5;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}