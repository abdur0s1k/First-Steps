#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
using namespace  std;

void bubbleSort(char* arr, int size);

int main()
{
    setlocale(0, "");
    const int SIZE = 10;
    char arr[SIZE] = { 'a', 'c', 'b', ' ', 'f', 'e', 'd', '3', '2', '1' };
    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " "; 
    }
    bubbleSort(arr, SIZE);
    cout << "\nОтсортированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " "; 
    }
    return 0;
}
void bubbleSort(char* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем местами элементы
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
