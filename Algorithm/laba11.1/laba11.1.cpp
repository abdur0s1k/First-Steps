#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

struct green {
	bool flower;
	int kolichestvo;
	double rost;
	string name;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	green tree;

	tree.flower = false;
	tree.kolichestvo = 5;
	tree.rost = 6;
	tree.name = "birch";

	cout << " ���������� �� ����� �������: " << tree.kolichestvo << " ������� ����: " << tree.rost << " ���: " << tree.name;

}
