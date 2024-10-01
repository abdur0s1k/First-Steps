#include <iostream>
using namespace std;

int findMinIndex(int arr[], int start, int end) { // ������� ��� ������ ������������ �������� � ����������
    int minIndex = start;    // ������ ������������ ��������
    for (int i = start + 1; i <= end; i++) {    // ����� ������������ �������� � ����������
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
void selectionSort(int arr[], int size) { // ������� ��� ���������� ������� �������
    for (int i = 0; i < size - 1; i++) {     // �������� �� ����� �������
        int minIndex = findMinIndex(arr, i, size - 1);         // ������� ������ ������������ �������� � ����������
        int temp = arr[i];         // ������ ������� ������� ������� � ����������� �������
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
// ������� ��� ������ ������� �� �����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 4, 2, 11, 3, 5, 7 };    // �������� ������ ����� �����
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array: " << endl;   // ����� ������������������ ������� �� �����
    printArray(arr, size);
    selectionSort(arr, size);   // ���������� ������� � ������� ���������� �������
    cout << "Sorted array: " << endl;
    printArray(arr, size); // ����� ���������������� ������� �� �����
    return 0;
}
