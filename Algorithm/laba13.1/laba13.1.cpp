#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    setlocale(0,"");

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
    char** arr = new char* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new char[cols];
    }

    // ���� ��������� �������
    cout << "������� �������� �������:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // ����� ��������� ������� � ���� �������
    cout << "�������� �������:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
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