#include <iostream>
#include <list>
#include <string>
using namespace std;
struct HotelGuest {
    string passportData;
    string arrivalDate;
    string departureDate;
    int roomNumber;

    int getStayDuration() {
        // Реализация метода подсчета количества дней пребывания
        // Возвращаем разницу между датами приезда и отъезда
        // Например, с использованием сторонней библиотеки для работы с датами
        return 0; // замените на реальную реализацию
    }
};

class HashTable {
private:
    static const int tableSize = 10;
    list<HotelGuest> table[tableSize];

public:
    int hashFunction(const string& passportData) {
        // Пример простой хеш-функции
        int hash = 0;
        for (char ch : passportData) {
            hash += ch;
        }
        return hash % tableSize;
    }

    void insert(const HotelGuest& guest) {
        int index = hashFunction(guest.passportData);
        table[index].push_back(guest);
    }

    void remove(const string& passportData) {
        int index = hashFunction(passportData);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->passportData == passportData) {
                table[index].erase(it);
                break;
            }
        }
    }

    HotelGuest* search(const string& passportData) {
        int index = hashFunction(passportData);
        for (auto& guest : table[index]) {
            if (guest.passportData == passportData) {
                return &guest;
            }
        }
        return nullptr;
    }
};

int main() {
    HashTable hotelGuests;

    HotelGuest guest1;
    guest1.passportData = "AB123456";
    guest1.arrivalDate = "2022-01-01";
    guest1.departureDate = "2022-01-10";
    guest1.roomNumber = 101;

    hotelGuests.insert(guest1);

    HotelGuest* foundGuest = hotelGuests.search("AB123456");
    if (foundGuest != nullptr) {
        cout << "Guest found: Room number " << foundGuest->roomNumber << endl;
    }
    else {
        cout << "Guest not found" << endl;
    }

    hotelGuests.remove("AB123456");

    return 0;
}