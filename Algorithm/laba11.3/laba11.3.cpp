#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
struct MAGAS {
	int kolvo, produkt;
	double posetitel, prodaji;
	string name;
	double srednie;
};
int main() {
	MAGAS x;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout << "Введите количество магазинов в N-ом районе: ";
	cin >> x.kolvo;
	cout << "Введите среднеее количесвто проданных товаров в магазине: ";
	cin >> x.produkt;
	cout << "Введите среднее количесвто посетителей: ";
	cin >> x.posetitel;
	cout << "Введите средний чек: ";
	cin >> x.prodaji;
	cout << "Ведите название магазина: ";
	cin >> x.name;
	cout << "Введите среднее количество проданного молока на один чек: ";
	cin >> x.srednie;

	cout << "| Название магазина: " << x.name << " | " << "Количество магазинов в N-ом районе: " << x.kolvo << " | Среднее количество проданных товаров магазинов: " << x.produkt << " | Среднее количество посетителей: " << x.posetitel << " | Средний чук: " << x.prodaji << " | Cредние количество проданного молока: " << x.srednie << " |";


}
