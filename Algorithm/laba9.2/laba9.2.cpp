#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    setlocale(0,"");

    vector<double> arr = { 1, 2, 3, 4, 5 };

    // ���������� �� �����������
    sort(arr.begin(), arr.end());
    cout << "��������������� ������ �� �����������: ";
    for (double num : arr) {
        cout << num << " ";
    }

    cout << endl;

    // ���������� �� ��������
    sort(arr.rbegin(), arr.rend());
    cout << "��������������� ������ �� ��������: ";
    for (double num : arr) {
        cout << num << " ";
    }

    return 0;
}