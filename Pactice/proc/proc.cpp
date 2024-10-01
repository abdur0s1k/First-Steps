#include <iostream>
using namespace std;
void Z1() {

    int a[100];
    int n;

    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        a[i] = 1 + i * 2;

    for (int i = 0; i < n; ++i)
        cout << "a[" << i << "]=" << a[i] << endl;
}
void Z2() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i < n; ++i)
    {
        a[0] = 2;
        a[i] = a[i - 1] * 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\narray[" << i << "]=" << a[i];
    }
    cout << endl << a[10];
}
void Z3() {

    int n[100];
    int c;
    int a, d;

    cin >> c;
    cout << "A + D" << endl;
    cin >> a;
    cin >> d;

    for (int i = 0; i < c; i++)
    {
        n[i] = a + (i * d);
    }

    for (int i = 0; i < c; ++i)
    {
        cout << "a[" << i << "]=" << n[i] << endl;
    }
}
void Z4() {
    int n, a, d;
    cin >> n >> a >> d;
    int arr[]{ n };

    for (int i = 0; i <= n; i++)
    {
        arr[i] = a * pow(d, i);
        cout << arr[i] << endl;
    }
}
void Z6() {
    int N, sum = 0;
    cin >> N;
    int mas[100];
    int A, B;
    cin >> A;
    cin >> B;

    for (int i = 2; i < N; ++i) {
        mas[0] = A;
        mas[1] = B;
        sum = (mas[i - 2] + mas[i - 1]);
        mas[i] = sum;

    }
    for (int i = 0; i < N; i++) {
        cout << mas[i] << endl;
    }
}
void Z7() {

    int a[10];
    int n, i;

    cout << "N:";
    cin >> n;
    for (i = 0; i < n; ++i) {
        cout << "a[" << i << "]:";
        cin >> a[i];
    }
    for (i = n - 1; i >= 0; --i)
        cout << "a[" << i << "]=" << a[i] << endl;
}void Z8() {
    
}
int main() {

}