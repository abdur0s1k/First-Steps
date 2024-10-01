#include <iostream>
#include <string>

using namespace std;

// Структура для клиента банка
struct BankClient {
    string full_name;
    string account_number;
    double balance;
    double interest_rate;

    // Метод для расчета баланса после начисления процентов
    void calculate_balance_with_interest() {
        double interest_amount = balance * (interest_rate / 100);
        balance += interest_amount;
    }
};

// Узел связанного списка
struct Node {
    BankClient data;
    Node* next;

    Node(const BankClient& client) : data(client), next(nullptr) {}
};

// Класс стека
class Stack {
private:
    Node* top;

public:
    // Конструктор
    Stack() : top(nullptr) {}

    // Деструктор для освобождения памяти, занятой узлами
    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }

    // Проверка на пустоту
    bool is_empty() {
        return top == nullptr;
    }

    // Добавление элемента в стек
    void push(const BankClient& client) {
        Node* newNode = new Node(client);
        newNode->next = top;
        top = newNode;
    }

    // Извлечение элемента из стека
    BankClient pop() {
        if (is_empty()) {
            cerr << "Error: Stack is empty." << endl;
            exit(1);
        }

        Node* temp = top;
        BankClient popped_data = top->data;
        top = top->next;
        delete temp;
        return popped_data;
    }

    // Вывод верхнего элемента стека
    void peek() {
        if (!is_empty()) {
            cout << "Name: " << top->data.full_name << endl;
            cout << "Account Number: " << top->data.account_number << endl;
            cout << "Balance: " << top->data.balance << endl;
            cout << "Interest Rate: " << top->data.interest_rate << "%" << endl;
        }
        else {
            cout << "Stack is empty." << endl;
        }
    }

    // Вывод всего стека
    void display() {
        if (!is_empty()) {
            cout << "Stack contents:" << endl;
            Node* current = top;
            while (current != nullptr) {
                cout << "Name: " << current->data.full_name << endl;
                cout << "Account Number: " << current->data.account_number << endl;
                cout << "Balance: " << current->data.balance << endl;
                cout << "Interest Rate: " << current->data.interest_rate << "%" << endl;
                cout << "---------------------" << endl;
                current = current->next;
            }
        }
        else {
            cout << "Stack is empty." << endl;
        }
    }
};

int main() {
    Stack stack;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add client to stack" << endl;
        cout << "2. Remove client from stack" << endl;
        cout << "3. Display client on top of stack" << endl;
        cout << "4. Display all clients in stack" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            BankClient client;
            cout << "Enter client's full name: ";
            cin.ignore();
            getline(cin, client.full_name);
            cout << "Enter account number: ";
            cin >> client.account_number;
            cout << "Enter balance: ";
            cin >> client.balance;
            cout << "Enter interest rate (%): ";
            cin >> client.interest_rate;
            client.calculate_balance_with_interest();
            stack.push(client);
            cout << "Client added to stack." << endl;
            break;
        }
        case 2: {
            if (!stack.is_empty()) {
                BankClient removed_client = stack.pop();
                cout << "Removed client: " << removed_client.full_name << endl;
            }
            else {
                cout << "Stack is empty." << endl;
            }
            break;
        }
        case 3: {
            stack.peek();
            break;
        }
        case 4: {
            stack.display();
            break;
        }
        case 5: {
            cout << "Exiting..." << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
        }
    }

    return 0;
}
