#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    setlocale(0, "");
    int num1, num2;
    cout << "������� ��������: ";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);
    cout << "�������: " << num1 << " � " << num2 << " ���: " << result << endl;

    return 0;
}
