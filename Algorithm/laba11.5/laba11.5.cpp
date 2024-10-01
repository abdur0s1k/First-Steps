#include<iostream>
#include<string>
using namespace std;
struct lufi {
	double age;
	string name;
};
int main() {
	lufi zoro;
	lufi& zoro1 = zoro;
	
	zoro1.age = 10;
	zoro1.name = "Adam";
	
	cout << "| " << zoro1.age << " | " << zoro1.name << " |";
	
	return(0);
}
