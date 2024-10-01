#include <iostream>
using namespace std;

int findMinIndex(int arr[], int start, int end) { // Функция для поиска минимального элемента в подмассиве
    int minIndex = start;    // Индекс минимального элемента
    for (int i = start + 1; i <= end; i++) {    // Поиск минимального элемента в подмассиве
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
void selectionSort(int arr[], int size) { // Функция для сортировки массива выбором
    for (int i = 0; i < size - 1; i++) {     // Проходим по всему массиву
        int minIndex = findMinIndex(arr, i, size - 1);         // Находим индекс минимального элемента в подмассиве
        int temp = arr[i];         // Меняем местами текущий элемент и минимальный элемент
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
// Функция для вывода массива на экран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 4, 2, 11, 3, 5, 7 };    // Исходный массив целых чисел
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array: " << endl;   // Вывод неотсортированного массива на экран
    printArray(arr, size);
    selectionSort(arr, size);   // Сортировка массива с помощью сортировки выбором
    cout << "Sorted array: " << endl;
    printArray(arr, size); // Вывод отсортированного массива на экран
    return 0;
}
