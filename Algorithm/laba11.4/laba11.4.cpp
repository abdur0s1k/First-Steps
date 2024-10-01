#include <iostream>
using namespace std;
struct Person {
    string name;
    int age;
};
int main() {
    Person person1;
    Person* ptrPerson = &person1;
    ptrPerson->name = "John";
    ptrPerson->age = 25;
    cout << "Name: " << ptrPerson->name << endl;
    cout << "Age: " << ptrPerson->age << endl;
    return 0;
}
