#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(0, "");
    string str = "hello";
    int n = str.length();

    // ���������� ������ �� ��������
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] < str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    cout << "��������������� ������ �� ��������: " << str << endl;

    return 0;
}