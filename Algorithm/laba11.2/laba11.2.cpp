#include <iostream>
#include<windows.h>
#include<string>
using namespace std;
struct Car {
	string name;
	string day;
	int month;
	string color;
	int bak;
	string korobka;
	string country;
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Car BMW;
	BMW.name = "BMW-m4 g82";
	BMW.day = "��������";
	BMW.month = 2020;
	BMW.color = "������";
	BMW.korobka = "�������";
	BMW.country = "��������";
	cout << "| " << BMW.name << " | ����� �������: " << BMW.day << " | ��� �������: " << BMW.month << " | ����: " << BMW.color << " | �������: " << BMW.korobka << " | ������ ������������: " << BMW.country;
}
