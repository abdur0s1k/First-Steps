#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Структура "Автомастерская"
struct AutoShop {
    int numberOfCars;
    double totalRevenue;
    char location;
    bool isOpen;
    static constexpr size_t MAX_NAME_LENGTH = 50;
    char shopName[MAX_NAME_LENGTH];
    static constexpr size_t MAX_EMPLOYEES = 10;
    int employees[MAX_EMPLOYEES];

    // Метод для вывода информации о автомастерской
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

// Функция для записи структуры в файл
void writeAutoShopToFile(const AutoShop& shop, const string& filename) {
    ofstream outFile(filename, ios::app | ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&shop), sizeof(AutoShop));
        outFile.close();
        cout << "Автомастерская успешно добавлена в файл." << endl;
    }
    else {
        cerr << "Ошибка открытия файла для записи." << endl;
    }
}

// Функция для чтения и вывода одной структуры из файла
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
        cerr << "Ошибка открытия файла для чтения." << endl;
    }
}

// Функция для чтения и вывода всех структур из файла
void readAndDisplayAllAutoShops(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (inFile.is_open()) {
        AutoShop shop;
        size_t structureNumber = 0;
        while (inFile.read(reinterpret_cast<char*>(&shop), sizeof(AutoShop))) {
            cout << "Автомастерская #" << structureNumber + 1 << endl;
            shop.displayInfo();
            cout << endl;
            ++structureNumber;
        }
        inFile.close();
    }
    else {
        cerr << "Ошибка открытия файла для чтения." << endl;
    }
}

// Функция для удаления файла
void deleteFile(const string& filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "Файл успешно удален." << endl;
    }
    else {
        cerr << "Ошибка удаления файла." << endl;
    }
}

int main() {
    setlocale(0, "");
    const string filename = "auto_shops.dat";

    while (true) {
        cout << "Меню:" << endl;
        cout << "0 - Выход" << endl;
        cout << "1 - Добавить автомастерскую в файл" << endl;
        cout << "2 - Прочитать и вывести одну автомастерскую с указанием номера" << endl;
        cout << "3 - Прочитать и вывести все автомастерские" << endl;
        cout << "4 - Удалить файл" << endl;

        int choice;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Программа завершена." << endl;
            return 0;
        case 1: {
            AutoShop newShop;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            cout << "Введите название автомастерской: ";
            cin.getline(newShop.shopName, AutoShop::MAX_NAME_LENGTH);
            cout << "Введите количество машин: ";
            cin >> newShop.numberOfCars;
            cout << "Введите общий доход: ";
            cin >> newShop.totalRevenue;
            cout << "Введите местоположение (символ): ";
            cin >> newShop.location;
            cout << "Введите, открыта ли мастерская (1 - Да, 0 - Нет): ";
            cin >> newShop.isOpen;
            cout << "Введите список сотрудников (максимум " << AutoShop::MAX_EMPLOYEES << " чисел): ";
            for (size_t i = 0; i < AutoShop::MAX_EMPLOYEES; ++i) {
                cin >> newShop.employees[i];
            }
            writeAutoShopToFile(newShop, filename);
            break;
        }
        case 2: {
            int structureNumber;
            cout << "Введите номер автомастерской: ";
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
            cout << "Некорректный ввод. Пожалуйста, введите снова." << endl;
        }
    }

    return 0;
}