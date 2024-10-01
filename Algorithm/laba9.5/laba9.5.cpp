#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");
    const int SIZE = 10;
    int arr[SIZE] = { 25, 22, 37, 31, 59, 11, 81, 44, 65, 10 };
    int num;
    int left = 0;
    int right = SIZE - 1;
    int mid = (left + right) / 2;
    bool isFound = false;

    cout << "¬ведите число: ";
    cin >> num;

    while (left <= right) {
        if (num == arr[mid]) {
            isFound = true;
            break;
        }
        else if (num < arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

        mid = (left + right) / 2;
    }

    if (isFound) {
        cout << "„исло " << num << " найдено на позиции " << mid + 1 << endl;
    }
    else {
        cout << "„исло " << num << " не найдено" << endl;
    }

    return 0;
}
