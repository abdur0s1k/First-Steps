#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(0, "");
    const int SIZE = 10;
    int arr[SIZE] = { 25, 22, 37, 31, 59, 11, 81, 44, 65, 10 };
    cout << "�������� ������: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    // ���������� �� ����������� ���� ��������
    for (int i = 0; i < SIZE - 1; i++) {
        int min = i;
        for (int j = i + 1; j < SIZE; j++) {
            if ((arr[j] / 10) % 10 < (arr[min] / 10) % 10) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    cout << "\n������ �� ����������� ���� ��������: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}