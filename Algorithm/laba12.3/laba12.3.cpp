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
    cout << "¬ведите двачисла: ";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);
    cout << "—редние: " << num1 << " и " << num2 << " это: " << result << endl;

    return 0;
}
