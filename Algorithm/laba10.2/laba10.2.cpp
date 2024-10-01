#include <iostream>
using namespace std;
int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    while (rows <= 0) {
        cout << "Number of rows should be a positive integer. Please enter again: ";
        cin >> rows;
    }

    cout << "Enter the number of columns: ";
    cin >> cols;

    while (cols <= 0) {
        cout << "Number of columns should be a positive integer. Please enter again: ";
        cin >> cols;
    }

    double** arr = new double* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[cols];
    }

    if (arr == nullptr) {
        cout << "Memory allocation failed. Exiting program." << endl;
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter the value for element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "Print array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j != cols - 1) {
                cout << arr[i][j] << " ; ";
            }
            else {
                cout << arr[i][j];
            }
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}