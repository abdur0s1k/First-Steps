#include <iostream>
#include <string>

using namespace std;

// Структура для хранения информации о виниловой пластинке
struct VinylRecord {
    string artist;      // Исполнитель
    string genre;       // Жанр
    string album_name;  // Название альбома
    int circulation;    // Тираж

    // Конструктор
    VinylRecord(string artist, string genre, string album_name, int circulation) : artist(artist), genre(genre), album_name(album_name), circulation(circulation) {}
};

// Узел односвязанного списка
class Node {
public:
    VinylRecord* data;  // Указатель на данные (виниловую пластинку)
    Node* next;         // Указатель на следующий узел

    // Конструктор
    Node(VinylRecord* record) : data(record), next(nullptr) {}
};

// Класс хеш-таблицы
class HashTable {
private:
    static const int TABLE_SIZE = 100;  // Размер хеш-таблицы
    Node* table[TABLE_SIZE];            // Массив указателей на узлы

    // Хеш-функция для определения индекса в хеш-таблице
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    // Конструктор
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;  // Инициализация всех указателей нулевыми значениями
        }
    }

    // Метод добавления записи в хеш-таблицу
    void addRecord(VinylRecord* record) {
        int index = hashFunction(record->album_name);  // Вычисление индекса в таблице
        Node* newNode = new Node(record);              // Создание нового узла
        newNode->next = table[index];                  // Установка связи с текущим первым узлом
        table[index] = newNode;                        // Новый узел становится первым в списке
    }

    // Метод поиска записи по названию альбома
    VinylRecord* findRecord(const string& album_name) {
        int index = hashFunction(album_name);  // Вычисление индекса в таблице
        Node* current = table[index];           // Указатель на текущий узел
        while (current != nullptr) {
            if (current->data->album_name == album_name) {
                return current->data;  // Найдена запись, возвращаем указатель на данные
            }
            current = current->next;   // Переходим к следующему узлу
        }
        return nullptr;  // Запись не найдена
    }

    // Метод удаления записи по названию альбома
    bool removeRecord(const string& album_name) {
        int index = hashFunction(album_name);  // Вычисление индекса в таблице
        Node* current = table[index];           // Указатель на текущий узел
        Node* prev = nullptr;                   // Указатель на предыдущий узел
        while (current != nullptr) {
            if (current->data->album_name == album_name) {
                if (prev != nullptr) {
                    prev->next = current->next;  // Устанавливаем связь между предыдущим и следующим узлом
                }
                else {
                    table[index] = current->next;  // Устанавливаем новый первый узел списка
                }
                delete current;  // Удаляем текущий узел
                return true;
            }
            prev = current;       // Переходим к следующему узлу
            current = current->next;
        }
        return false;  // Запись не найдена
    }

    // Метод вывода данных о пластинках с тиражом более 10000 экземпляров
    void printRecordsOver10000Circulation() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];  // Указатель на текущий узел
            while (current != nullptr) {
                if (current->data->circulation > 10000) {
                    cout << "Исполнитель: " << current->data->artist << ", Альбом: " << current->data->album_name << ", Тираж: " << current->data->circulation << endl;
                }
                current = current->next;  // Переходим к следующему узлу
            }
        }
    }
};

int main() {
    setlocale(0,"");
    // Создаем объект класса HashTable
    HashTable hashTable;

    // Создаем несколько виниловых пластинок
    VinylRecord vinyl1("The Beatles", "Rock", "Abbey Road", 15000);
    VinylRecord vinyl2("Michael Jackson", "Pop", "Thriller", 25000);
    VinylRecord vinyl3("Pink Floyd", "Rock", "The Dark Side of the Moon", 20000);
    VinylRecord vinyl4("The Beatles", "Rock", "Abbey Road", 150);

    // Добавляем виниловые пластинки в хеш-таблицу
    hashTable.addRecord(&vinyl1);
    hashTable.addRecord(&vinyl2);
    hashTable.addRecord(&vinyl3);

    // Выводим информацию о пластинках с тиражом более 10000 экземпляров
    hashTable.printRecordsOver10000Circulation();

    return 0;
}
