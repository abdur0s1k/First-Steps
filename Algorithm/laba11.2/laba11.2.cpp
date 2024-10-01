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
	BMW.day = "Сентябрь";
	BMW.month = 2020;
	BMW.color = "Желтый";
	BMW.korobka = "Автомат";
	BMW.country = "Германия";
	cout << "| " << BMW.name << " | Месяц выпуска: " << BMW.day << " | Год выпуска: " << BMW.month << " | Цвет: " << BMW.color << " | Коробка: " << BMW.korobka << " | Страна производства: " << BMW.country;
}
