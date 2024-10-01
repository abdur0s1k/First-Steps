#include<iostream>
#include<string>
using namespace std;
struct lufi {
	double age;
	string name;
};
int main() {
	int const n = 3;
	lufi zoro[n];
	zoro[0].age = 10;
	zoro[0].name = "Adam";
	zoro[1].age = 40;
	zoro[1].name = "Eva";
	zoro[2].age = 59;
	zoro[2].name = "Nana";
	for (int i = 0; i < n; i++) {
		cout << "Name: " << zoro[i].name << endl << "\t";
		cout << "Age: " << zoro[i].age << endl;
	}
	return(0);
}
