#include <iostream>
#include <string>
using namespace std;

// ��������� ������ ��� �������� ���������� � ����������
struct Employee {
    string fullName; // ���
    int employeeID; // ��������� �����
    int hoursWorked; // ���������� ������������ �����
    double hourlyRate; // ��������� ������

    // ����������� ��� ������������� ����� ���������
    Employee(string name, int id, int hours, double rate) : fullName(name), employeeID(id), hoursWorked(hours), hourlyRate(rate) {}

    // ����� ��� ���������� ���������� ����� � ������ ������
    double calculateSalary() const {
        double totalSalary = hoursWorked <= 144 ? hoursWorked * hourlyRate : (144 * hourlyRate) + ((hoursWorked - 144) * hourlyRate * 2);
        return totalSalary * 0.88; // 12% ����������� ������
    }

    // ����� ��� ������ ���������� � ����������
    void displayInfo() const {
        cout << "���������� � ����������:\n";
        cout << "���: " << fullName << endl;
        cout << "��������� �����: " << employeeID << endl;
        cout << "������������ ����: " << hoursWorked << endl;
        cout << "��������� ������: " << hourlyRate << endl;
        cout << "���������� ����� ����� ������ ������: " << calculateSalary() << endl;
    }
};

// ��������� ���� �������
struct QueueNode {
    Employee data; // ������ � ����������
    QueueNode* next; // ��������� �� ��������� ����

    // �����������
    QueueNode(const Employee& newData) : data(newData), next(nullptr) {}
};

// ����� �������
class EmployeeQueue {
private:
    QueueNode* front; // ��������� �� �������� ���� �������
    QueueNode* rear; // ��������� �� ������ ���� �������

public:
    // �����������
    EmployeeQueue() : front(nullptr), rear(nullptr) {}

    // ���������� ��� ������������ ������
    ~EmployeeQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // �������� �� �������
    bool isEmpty() const {
        return front == nullptr;
    }

    // ���������� �������� � �������
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

    // ���������� �������� �� �������
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

    // ��������� ������� �������� � �������
    const Employee& getFront() const {
        if (isEmpty()) {
            throw runtime_error("������� �����");
        }
        return front->data;
    }
};

// ������� ��� ���������� ���������� � �������
void addEmployee(EmployeeQueue& queue) {
    string name;
    int id, hours;
    double rate;
    cout << "������� ��� ����������: ";
    cin.ignore();
    getline(cin, name);
    cout << "������� ��������� ����� ����������: ";
    cin >> id;
    cout << "������� ���������� ������������ �����: ";
    cin >> hours;
    cout << "������� ��������� �����: ";
    cin >> rate;
    queue.enqueue(Employee(name, id, hours, rate));
}

// ������� ��� ���������� ���������� �� �������
void extractEmployee(EmployeeQueue& queue) {
    if (!queue.isEmpty()) {
        const Employee& extractedEmployee = queue.getFront();
        cout << "�������� ���������: " << extractedEmployee.fullName << endl;
        queue.dequeue();
    }
    else {
        cout << "������� �����." << endl;
    }
}

// ������� ��� ������ ���������� � ����������
void displayEmployeeInfo(const EmployeeQueue& queue) {
    if (!queue.isEmpty()) {
        const Employee& employeeToPrint = queue.getFront();
        employeeToPrint.displayInfo();
    }
    else {
        cout << "������� �����." << endl;
    }
}

// ������� ��� ������ ���� ������� �� �����
void displayQueue(const EmployeeQueue& queue) {
    if (!queue.isEmpty()) {
        EmployeeQueue tempQueue = queue;
        cout << "������ ����������� � �������:" << endl;
        while (!tempQueue.isEmpty()) {
            const Employee& employee = tempQueue.getFront();
            employee.displayInfo();
            tempQueue.dequeue();
        }
    }
    else {
        cout << "������� �����." << endl;
    }
}

int main() {
    setlocale(0,"");
    EmployeeQueue queue;
    int choice;
    do {
        cout << "\n���� ����������:" << endl;
        cout << "1. ���������� ����������" << endl;
        cout << "2. ���������� ����������" << endl;
        cout << "3. ����� ���������� � ����������" << endl;
        cout << "4. ����� ����� ������ �� �����" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
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
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����. ���������� �����." << endl;
        }
    } while (choice != 0);

    return 0;
}
