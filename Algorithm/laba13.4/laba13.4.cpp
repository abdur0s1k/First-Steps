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
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    if (arr == nullptr) {
        cout << "������ ��������� ������\n";
        return 1;
    }

    // ������������� ��������� �������
    int value = -950;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value;
            value += 25;
        }
    }

    // ����� ��������� ������� � ���� �������
    cout << "Print massiv:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] * 5; // ���������� �������� � 5 ���
            if (j != cols - 1) {
                cout << " | ";
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