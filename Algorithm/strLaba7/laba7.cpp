#include <iostream>
#include <string>

using namespace std;

// ��������� ��� �������� ���������� � ��������� ���������
struct VinylRecord {
    string artist;      // �����������
    string genre;       // ����
    string album_name;  // �������� �������
    int circulation;    // �����

    // �����������
    VinylRecord(string artist, string genre, string album_name, int circulation) : artist(artist), genre(genre), album_name(album_name), circulation(circulation) {}
};

// ���� �������������� ������
class Node {
public:
    VinylRecord* data;  // ��������� �� ������ (��������� ���������)
    Node* next;         // ��������� �� ��������� ����

    // �����������
    Node(VinylRecord* record) : data(record), next(nullptr) {}
};

// ����� ���-�������
class HashTable {
private:
    static const int TABLE_SIZE = 100;  // ������ ���-�������
    Node* table[TABLE_SIZE];            // ������ ���������� �� ����

    // ���-������� ��� ����������� ������� � ���-�������
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    // �����������
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;  // ������������� ���� ���������� �������� ����������
        }
    }

    // ����� ���������� ������ � ���-�������
    void addRecord(VinylRecord* record) {
        int index = hashFunction(record->album_name);  // ���������� ������� � �������
        Node* newNode = new Node(record);              // �������� ������ ����
        newNode->next = table[index];                  // ��������� ����� � ������� ������ �����
        table[index] = newNode;                        // ����� ���� ���������� ������ � ������
    }

    // ����� ������ ������ �� �������� �������
    VinylRecord* findRecord(const string& album_name) {
        int index = hashFunction(album_name);  // ���������� ������� � �������
        Node* current = table[index];           // ��������� �� ������� ����
        while (current != nullptr) {
            if (current->data->album_name == album_name) {
                return current->data;  // ������� ������, ���������� ��������� �� ������
            }
            current = current->next;   // ��������� � ���������� ����
        }
        return nullptr;  // ������ �� �������
    }

    // ����� �������� ������ �� �������� �������
    bool removeRecord(const string& album_name) {
        int index = hashFunction(album_name);  // ���������� ������� � �������
        Node* current = table[index];           // ��������� �� ������� ����
        Node* prev = nullptr;                   // ��������� �� ���������� ����
        while (current != nullptr) {
            if (current->data->album_name == album_name) {
                if (prev != nullptr) {
                    prev->next = current->next;  // ������������� ����� ����� ���������� � ��������� �����
                }
                else {
                    table[index] = current->next;  // ������������� ����� ������ ���� ������
                }
                delete current;  // ������� ������� ����
                return true;
            }
            prev = current;       // ��������� � ���������� ����
            current = current->next;
        }
        return false;  // ������ �� �������
    }

    // ����� ������ ������ � ���������� � ������� ����� 10000 �����������
    void printRecordsOver10000Circulation() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];  // ��������� �� ������� ����
            while (current != nullptr) {
                if (current->data->circulation > 10000) {
                    cout << "�����������: " << current->data->artist << ", ������: " << current->data->album_name << ", �����: " << current->data->circulation << endl;
                }
                current = current->next;  // ��������� � ���������� ����
            }
        }
    }
};

int main() {
    setlocale(0,"");
    // ������� ������ ������ HashTable
    HashTable hashTable;

    // ������� ��������� ��������� ���������
    VinylRecord vinyl1("The Beatles", "Rock", "Abbey Road", 15000);
    VinylRecord vinyl2("Michael Jackson", "Pop", "Thriller", 25000);
    VinylRecord vinyl3("Pink Floyd", "Rock", "The Dark Side of the Moon", 20000);
    VinylRecord vinyl4("The Beatles", "Rock", "Abbey Road", 150);

    // ��������� ��������� ��������� � ���-�������
    hashTable.addRecord(&vinyl1);
    hashTable.addRecord(&vinyl2);
    hashTable.addRecord(&vinyl3);

    // ������� ���������� � ���������� � ������� ����� 10000 �����������
    hashTable.printRecordsOver10000Circulation();

    return 0;
}
