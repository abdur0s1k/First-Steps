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

    char** arr = new char* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new char[cols];
    }

    if (arr == nullptr) {
        cout << "Memory allocation failed. Exiting program." << endl;
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> arr[i][j];
        }
    }

    cout << "Print array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
