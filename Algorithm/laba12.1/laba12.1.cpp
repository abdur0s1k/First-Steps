#include<iostream>
#include<string>
#include<fstream>
#include <algorithm>
using namespace std;
void swap(char& a, char& b);
void generatePermutations(string& str, int start, int end);
int main() {
	setlocale(0, "");
	string path = "Input.txt";
	string outpath = "Output.txt";
	ofstream out;//������ � ����
	ifstream inp;//������ �� �����
	out.open(outpath);
	inp.open(path);
	if (!inp.is_open()) {
		cout << "������ �������� input ��� output �����";
	}
	else {
		string str;
		while (!inp.eof()) {
			getline(inp, str);
		}
		int n = str.length();
		generatePermutations(str, 0, n - 1);
	}
	out.close();
	inp.close();
	return 0;
}
void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

// ����������� ������� ��� ��������� ������������
void generatePermutations(string& str, int start, int end) {
	ofstream out;//������ � ����
	if (start == end) {
		string outpath = "Output.txt";

		out.open(outpath, ios::app);
		out << str << std::endl;
		return;
	}
	out.close();
	for (int i = start; i <= end; ++i) {

		// ������ ������� ������ � ������ �� �����������
		swap(str[start], str[i]);
		// ����������� ����� ��� ���������� ����� ������
		generatePermutations(str, start + 1, end);
		// ���������� ������ � �������� ��������� (������ ������)
		swap(str[start], str[i]);
	}
}
