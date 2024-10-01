#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    int rows, cols;
    setlocale(0, "");

    // ���� ���������� �����
    do {
        cout << "������� ���������� �����: ";
        cin >> rows;
        if (rows <= 0) {
            cout << "���������� ����� ������ ���� ������������� ������\n";
        }
    } while (rows <= 0);

    // ���� ���������� ��������
    do {
        cout << "������� ���������� ��������: ";
        cin >> cols;
        if (cols <= 0) {
            cout << "���������� �������� ������ ���� ������������� ������\n";
        }
    } while (cols <= 0);

    // ��������� ������������ ������
    double** arr = new double* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[cols];
    }

    if (arr == nullptr) {
        cout << "������ ��������� ������\n";
        return 1;
    }

    // ������������� ��������� ������� ���������� ����������
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (rand() % 1000) / 10.0; // ��������� �������� �� 0 �� 100 � ��������� �� �������
        }
    }

    // ����� ��������� ������� � ���� �������
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

    // ����� ������ ���� �������
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

    // ������������ ������������ ������
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}