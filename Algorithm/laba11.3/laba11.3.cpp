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
	cout << "������� ���������� ��������� � N-�� ������: ";
	cin >> x.kolvo;
	cout << "������� �������� ���������� ��������� ������� � ��������: ";
	cin >> x.produkt;
	cout << "������� ������� ���������� �����������: ";
	cin >> x.posetitel;
	cout << "������� ������� ���: ";
	cin >> x.prodaji;
	cout << "������ �������� ��������: ";
	cin >> x.name;
	cout << "������� ������� ���������� ���������� ������ �� ���� ���: ";
	cin >> x.srednie;

	cout << "| �������� ��������: " << x.name << " | " << "���������� ��������� � N-�� ������: " << x.kolvo << " | ������� ���������� ��������� ������� ���������: " << x.produkt << " | ������� ���������� �����������: " << x.posetitel << " | ������� ���: " << x.prodaji << " | C������ ���������� ���������� ������: " << x.srednie << " |";


}
