#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ��������� "��������������"
struct AutoShop {
    int numberOfCars;
    double totalRevenue;
    char location;
    bool isOpen;
    static constexpr size_t MAX_NAME_LENGTH = 50;
    char shopName[MAX_NAME_LENGTH];
    static constexpr size_t MAX_EMPLOYEES = 10;
    int employees[MAX_EMPLOYEES];

    // ����� ��� ������ ���������� � ��������������
    void displayInfo() const {
        cout << "Shop Name: " << shopName << endl;
        cout << "Number of Cars: " << numberOfCars << endl;
        cout << "Total Revenue: " << totalRevenue << endl;
        cout << "Location: " << location << endl;
        cout << "Is Open: " << (isOpen ? "Yes" : "No") << endl;
        cout << "Employees: ";
        for (size_t i = 0; i < MAX_EMPLOYEES; ++i) {
            cout << employees[i] << " ";
        }
        cout << endl;
    }
};

// ������� ��� ������ ��������� � ����
void writeAutoShopToFile(const AutoShop& shop, const string& filename) {
    ofstream outFile(filename, ios::app | ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&shop), sizeof(AutoShop));
        outFile.close();
        cout << "�������������� ������� ��������� � ����." << endl;
    }
    else {
        cerr << "������ �������� ����� ��� ������." << endl;
    }
}

// ������� ��� ������ � ������ ����� ��������� �� �����
void readAndDisplayAutoShop(const string& filename, int structureNumber) {
    ifstream inFile(filename, ios::binary);
    if (inFile.is_open()) {
        AutoShop shop;
        inFile.seekg(structureNumber * sizeof(AutoShop), ios::beg);
        inFile.read(reinterpret_cast<char*>(&shop), sizeof(AutoShop));
        shop.displayInfo();
        inFile.close();
    }
    else {
        cerr << "������ �������� ����� ��� ������." << endl;
    }
}

// ������� ��� ������ � ������ ���� �������� �� �����
void readAndDisplayAllAutoShops(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (inFile.is_open()) {
        AutoShop shop;
        size_t structureNumber = 0;
        while (inFile.read(reinterpret_cast<char*>(&shop), sizeof(AutoShop))) {
            cout << "�������������� #" << structureNumber + 1 << endl;
            shop.displayInfo();
            cout << endl;
            ++structureNumber;
        }
        inFile.close();
    }
    else {
        cerr << "������ �������� ����� ��� ������." << endl;
    }
}

// ������� ��� �������� �����
void deleteFile(const string& filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "���� ������� ������." << endl;
    }
    else {
        cerr << "������ �������� �����." << endl;
    }
}

int main() {
    setlocale(0, "");
    const string filename = "auto_shops.dat";

    while (true) {
        cout << "����:" << endl;
        cout << "0 - �����" << endl;
        cout << "1 - �������� �������������� � ����" << endl;
        cout << "2 - ��������� � ������� ���� �������������� � ��������� ������" << endl;
        cout << "3 - ��������� � ������� ��� ��������������" << endl;
        cout << "4 - ������� ����" << endl;

        int choice;
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "��������� ���������." << endl;
            return 0;
        case 1: {
            AutoShop newShop;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������ �����
            cout << "������� �������� ��������������: ";
            cin.getline(newShop.shopName, AutoShop::MAX_NAME_LENGTH);
            cout << "������� ���������� �����: ";
            cin >> newShop.numberOfCars;
            cout << "������� ����� �����: ";
            cin >> newShop.totalRevenue;
            cout << "������� �������������� (������): ";
            cin >> newShop.location;
            cout << "�������, ������� �� ���������� (1 - ��, 0 - ���): ";
            cin >> newShop.isOpen;
            cout << "������� ������ ����������� (�������� " << AutoShop::MAX_EMPLOYEES << " �����): ";
            for (size_t i = 0; i < AutoShop::MAX_EMPLOYEES; ++i) {
                cin >> newShop.employees[i];
            }
            writeAutoShopToFile(newShop, filename);
            break;
        }
        case 2: {
            int structureNumber;
            cout << "������� ����� ��������������: ";
            cin >> structureNumber;
            readAndDisplayAutoShop(filename, structureNumber - 1);
            break;
        }
        case 3:
            readAndDisplayAllAutoShops(filename);
            break;
        case 4:
            deleteFile(filename);
            break;
        default:
            cout << "������������ ����. ����������, ������� �����." << endl;
        }
    }

    return 0;
}