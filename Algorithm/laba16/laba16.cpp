#include <iostream>
#include <fstream>
#include <cmath> // ��� ������������� ������� fabs
using namespace std;

int main() {
    setlocale(0, "");
    // ��������� ���� ��� ������
    ifstream file("f.txt");

    // �������� ���������� �������� �����
    if (!file.is_open()) {
        cerr << "�� ������� ������� ����!" << endl;
        return 1;
    }

    double value;
    double maxAbsoluteValue = 0.0; // �������������� ������������ �������� ������

    // ��������� ���������� �� ����� � ��������� �������� � ������� ������������ �������� ������
    for (int i = 1; file >> value; ++i) {
        if (i % 2 != 0) { // �������� �� ���������� ������ ����������
            double absoluteValue = fabs(value);
            if (absoluteValue > maxAbsoluteValue) {
                maxAbsoluteValue = absoluteValue;
            }
        }
    }

    // ��������� ����
    file.close();

    // ����� ����������
    cout << "���������� �������� ������ ��������� � ��������� ��������: " << maxAbsoluteValue << std::endl;

    return 0;
}