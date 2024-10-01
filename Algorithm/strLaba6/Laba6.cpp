#include <iostream>
#include <string>

using namespace std;

// Структура данных для хранения информации о клиенте банка
struct BankClient {
    string fullName;    // Фамилия И.О.
    string accountNumber;   // Номер счета
    double balance;     // Сумма на счете
    double interestRate;    // Процент
};

// Класс узла очереди
class QueueNode {
public:
    BankClient data; // Данные клиента
    QueueNode* next; // Указатель на следующий узел

    // Конструктор
    QueueNode(const BankClient& newData) : data(newData), next(nullptr) {}
};

// Класс очереди
class Queue {
private:
    QueueNode* front; // Указатель на передний узел очереди
    QueueNode* rear;  // Указатель на задний узел очереди

public:
    // Конструктор
    Queue() : front(nullptr), rear(nullptr) {}

    // Деструктор для освобождения памяти
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return front == nullptr;
    }

    // Добавление элемента в очередь
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

    // Извлечение элемента из очереди
    void dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
            return;
        }
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Получение первого элемента в очереди
    const BankClient& getFront() const {
        if (isEmpty()) {
            throw runtime_error("Очередь пуста.");
        }
        return front->data;
    }
};

// Функция для начисления процентов на счет клиента
void calculateInterest(BankClient& client) {
    double interest = client.balance * (client.interestRate / 100);
    client.balance += interest;
}

int main() {
    setlocale(0,"");
    Queue clients; // Очередь клиентов банка
    int choice;

    do {
        cout << "\nМеню приложения:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Извлечь клиента\n";
        cout << "3. Вывести информацию о клиенте\n";
        cout << "0. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(); // Очистить буфер ввода

        switch (choice) {
        case 1: {
            BankClient newClient;
            cout << "Введите ФИО клиента: ";
            getline(cin, newClient.fullName);
            cout << "Введите номер счета: ";
            getline(cin, newClient.accountNumber);
            cout << "Введите сумму на счете: ";
            cin >> newClient.balance;
            cout << "Введите процент: ";
            cin >> newClient.interestRate;
            cin.ignore(); // Очистить буфер ввода
            calculateInterest(newClient); // Начислить проценты
            clients.enqueue(newClient); // Добавить клиента в очередь
            cout << "Клиент добавлен." << endl;
            break;
        }
        case 2:
            if (!clients.isEmpty()) {
                const BankClient& extractedClient = clients.getFront();
                cout << "Извлечен клиент: " << extractedClient.fullName << endl;
                clients.dequeue(); // Извлечь клиента из очереди
            }
            else {
                cout << "Очередь пуста." << endl;
            }
            break;
        case 3:
            if (!clients.isEmpty()) {
                const BankClient& clientToPrint = clients.getFront();
                cout << "Информация о текущем клиенте:" << endl;
                cout << "ФИО: " << clientToPrint.fullName << endl;
                cout << "Номер счета: " << clientToPrint.accountNumber << endl;
                cout << "Сумма на счете: " << clientToPrint.balance << endl;
                cout << "Процент: " << clientToPrint.interestRate << "%" << endl;
            }
            else {
                cout << "Очередь пуста." << endl;
            }
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
