#include <iostream>
#include <string>
using namespace std;

// Структура данных для хранения информации о сотруднике
struct Employee {
    string fullName; // ФИО
    int employeeID; // Табельный номер
    int hoursWorked; // Количество отработанных часов
    double hourlyRate; // Почасовая ставка

    // Конструктор для инициализации полей структуры
    Employee(string name, int id, int hours, double rate) : fullName(name), employeeID(id), hoursWorked(hours), hourlyRate(rate) {}

    // Метод для вычисления заработной платы с учетом налога
    double calculateSalary() const {
        double totalSalary = hoursWorked <= 144 ? hoursWorked * hourlyRate : (144 * hourlyRate) + ((hoursWorked - 144) * hourlyRate * 2);
        return totalSalary * 0.88; // 12% подоходного налога
    }

    // Метод для вывода информации о сотруднике
    void displayInfo() const {
        cout << "Информация о сотруднике:\n";
        cout << "ФИО: " << fullName << endl;
        cout << "Табельный номер: " << employeeID << endl;
        cout << "Отработанные часы: " << hoursWorked << endl;
        cout << "Почасовая ставка: " << hourlyRate << endl;
        cout << "Заработная плата после вычета налога: " << calculateSalary() << endl;
    }
};

// Структура узла очереди
struct QueueNode {
    Employee data; // Данные о сотруднике
    QueueNode* next; // Указатель на следующий узел

    // Конструктор
    QueueNode(const Employee& newData) : data(newData), next(nullptr) {}
};

// Класс очереди
class EmployeeQueue {
private:
    QueueNode* front; // Указатель на передний узел очереди
    QueueNode* rear; // Указатель на задний узел очереди

public:
    // Конструктор
    EmployeeQueue() : front(nullptr), rear(nullptr) {}

    // Деструктор для освобождения памяти
    ~EmployeeQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return front == nullptr;
    }

    // Добавление элемента в очередь
    void enqueue(const Employee& newData) {
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
        if (!isEmpty()) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    // Получение первого элемента в очереди
    const Employee& getFront() const {
        if (isEmpty()) {
            throw runtime_error("Очередь пуста");
        }
        return front->data;
    }
};

// Функция для добавления сотрудника в очередь
void addEmployee(EmployeeQueue& queue) {
    string name;
    int id, hours;
    double rate;
    cout << "Введите ФИО сотрудника: ";
    cin.ignore();
    getline(cin, name);
    cout << "Введите табельный номер сотрудника: ";
    cin >> id;
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    cout << "Введите почасовой тариф: ";
    cin >> rate;
    queue.enqueue(Employee(name, id, hours, rate));
}

// Функция для извлечения сотрудника из очереди
void extractEmployee(EmployeeQueue& queue) {
    if (!queue.isEmpty()) {
        const Employee& extractedEmployee = queue.getFront();
        cout << "Извлечен сотрудник: " << extractedEmployee.fullName << endl;
        queue.dequeue();
    }
    else {
        cout << "Очередь пуста." << endl;
    }
}

// Функция для вывода информации о сотруднике
void displayEmployeeInfo(const EmployeeQueue& queue) {
    if (!queue.isEmpty()) {
        const Employee& employeeToPrint = queue.getFront();
        employeeToPrint.displayInfo();
    }
    else {
        cout << "Очередь пуста." << endl;
    }
}

// Функция для вывода всей очереди на экран
void displayQueue(const EmployeeQueue& queue) {
    if (!queue.isEmpty()) {
        EmployeeQueue tempQueue = queue;
        cout << "Список сотрудников в очереди:" << endl;
        while (!tempQueue.isEmpty()) {
            const Employee& employee = tempQueue.getFront();
            employee.displayInfo();
            tempQueue.dequeue();
        }
    }
    else {
        cout << "Очередь пуста." << endl;
    }
}

int main() {
    setlocale(0,"");
    EmployeeQueue queue;
    int choice;
    do {
        cout << "\nМеню приложения:" << endl;
        cout << "1. Добавление сотрудника" << endl;
        cout << "2. Извлечение сотрудника" << endl;
        cout << "3. Вывод информации о сотруднике" << endl;
        cout << "4. Вывод всего списка на экран" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addEmployee(queue);
            break;
        case 2:
            extractEmployee(queue);
            break;
        case 3:
            displayEmployeeInfo(queue);
            break;
        case 4:
            displayQueue(queue);
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
