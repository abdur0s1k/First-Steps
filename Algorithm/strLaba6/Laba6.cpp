#include <iostream>
#include <string>

using namespace std;

// ��������� ������ ��� �������� ���������� � ������� �����
struct BankClient {
    string fullName;    // ������� �.�.
    string accountNumber;   // ����� �����
    double balance;     // ����� �� �����
    double interestRate;    // �������
};

// ����� ���� �������
class QueueNode {
public:
    BankClient data; // ������ �������
    QueueNode* next; // ��������� �� ��������� ����

    // �����������
    QueueNode(const BankClient& newData) : data(newData), next(nullptr) {}
};

// ����� �������
class Queue {
private:
    QueueNode* front; // ��������� �� �������� ���� �������
    QueueNode* rear;  // ��������� �� ������ ���� �������

public:
    // �����������
    Queue() : front(nullptr), rear(nullptr) {}

    // ���������� ��� ������������ ������
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // �������� �� �������
    bool isEmpty() const {
        return front == nullptr;
    }

    // ���������� �������� � �������
    void enqueue(const BankClient& newData) {
        QueueNode* newNode = new QueueNode(newData);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // ���������� �������� �� �������
    void dequeue() {
        if (isEmpty()) {
            cout << "������� �����." << endl;
            return;
        }
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // ��������� ������� �������� � �������
    const BankClient& getFront() const {
        if (isEmpty()) {
            throw runtime_error("������� �����.");
        }
        return front->data;
    }
};

// ������� ��� ���������� ��������� �� ���� �������
void calculateInterest(BankClient& client) {
    double interest = client.balance * (client.interestRate / 100);
    client.balance += interest;
}

int main() {
    setlocale(0,"");
    Queue clients; // ������� �������� �����
    int choice;

    do {
        cout << "\n���� ����������:\n";
        cout << "1. �������� �������\n";
        cout << "2. ������� �������\n";
        cout << "3. ������� ���������� � �������\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";
        cin >> choice;
        cin.ignore(); // �������� ����� �����

        switch (choice) {
        case 1: {
            BankClient newClient;
            cout << "������� ��� �������: ";
            getline(cin, newClient.fullName);
            cout << "������� ����� �����: ";
            getline(cin, newClient.accountNumber);
            cout << "������� ����� �� �����: ";
            cin >> newClient.balance;
            cout << "������� �������: ";
            cin >> newClient.interestRate;
            cin.ignore(); // �������� ����� �����
            calculateInterest(newClient); // ��������� ��������
            clients.enqueue(newClient); // �������� ������� � �������
            cout << "������ ��������." << endl;
            break;
        }
        case 2:
            if (!clients.isEmpty()) {
                const BankClient& extractedClient = clients.getFront();
                cout << "�������� ������: " << extractedClient.fullName << endl;
                clients.dequeue(); // ������� ������� �� �������
            }
            else {
                cout << "������� �����." << endl;
            }
            break;
        case 3:
            if (!clients.isEmpty()) {
                const BankClient& clientToPrint = clients.getFront();
                cout << "���������� � ������� �������:" << endl;
                cout << "���: " << clientToPrint.fullName << endl;
                cout << "����� �����: " << clientToPrint.accountNumber << endl;
                cout << "����� �� �����: " << clientToPrint.balance << endl;
                cout << "�������: " << clientToPrint.interestRate << "%" << endl;
            }
            else {
                cout << "������� �����." << endl;
            }
            break;
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
        }
    } while (choice != 0);

    return 0;
}
