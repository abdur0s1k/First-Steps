#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    while (rows <= 0) {
        cout << "Number of rows must be a positive integer. Please try again: ";
        cin >> rows;
    }

    cout << "Enter the number of columns: ";
    cin >> cols;
    while (cols <= 0) {
        cout << "Number of columns must be a positive integer. Please try again: ";
        cin >> cols;
    }

    double** arr = new double* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[cols];
    }

    if (arr == nullptr) {
        cerr << "Failed to allocate memory. Exiting program.";
        return 1;
    }

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (rand() % 100) / 10.0; 
        }
    }

   
    cout << "Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    
    cout << "New vision of array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > 2) {
                cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
            }
        }
    }

   
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}