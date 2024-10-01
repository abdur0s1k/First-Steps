#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int factorial(int n);
int main() {
	setlocale(0, "");
	int n = 25;
	string path = "INPUT.txt";
	ofstream fout;
	fout.open(path);//,ofstream::app
	fout.is_open();
	if (!fout.is_open()) {
		cout << "Îøèáêà" << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			long int y = factorial(i);
			fout << i << ") " << y << "\n";

		}
	}
	fout.close();
}
int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
