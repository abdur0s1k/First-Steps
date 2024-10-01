#include <iostream>
using namespace std;
// Рекурсивная функция для вычисления суммы элементов массива
int recursiveSum(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    else {
        return arr[n - 1] + recursiveSum(arr, n - 1);
    }
}

// Рекурсивная функция для вычисления произведения элементов массива
int recursiveProduct(int arr[], int n) {
    if (n <= 0) {
        return 1;
    }
    else {
        return arr[n - 1] * recursiveProduct(arr, n - 1);
    }
}

int main() {
    setlocale(0, "");
    int size;
    cout << "Введите размер массива ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter " << size << "Введите числа в массиве: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int sum = recursiveSum(arr, size);
    int product = recursiveProduct(arr, size);

    cout << "Сумма элементов в массиве: " << sum << endl;
    cout << "Результат: " << product << endl;

    return 0;
}
