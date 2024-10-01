#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    setlocale(0,"");

    vector<double> arr = { 1, 2, 3, 4, 5 };

    // Сортировка по возрастанию
    sort(arr.begin(), arr.end());
    cout << "Отсортированный массив по возрастанию: ";
    for (double num : arr) {
        cout << num << " ";
    }

    cout << endl;

    // Сортировка по убыванию
    sort(arr.rbegin(), arr.rend());
    cout << "Отсортированный массив по убыванию: ";
    for (double num : arr) {
        cout << num << " ";
    }

    return 0;
}