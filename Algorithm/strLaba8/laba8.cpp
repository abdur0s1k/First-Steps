#include <iostream>
#include <string>

using namespace std;

// Класс для квитанции о сдаче радиоаппаратуры в ремонт
class RepairReceipt {
private:
    string productGroup;  // Наименование группы изделий
    string productBrand;  // Марка изделия
    string receptionDate; // Дата приемки
    string repairTime;    // Время ремонта

public:
    // Конструктор
    RepairReceipt(const string& group, const string& brand, const string& date, const string& time)
        : productGroup(group), productBrand(brand), receptionDate(date), repairTime(time) {}

    // Перегрузка оператора сравнения
    bool operator<(const RepairReceipt& other) const {
        // Сравниваем по дате приемки (допустим, что более ранняя дата имеет больший приоритет)
        return receptionDate < other.receptionDate;
    }

    // Метод для вывода информации о квитанции
    void printReceiptInfo() const {
        cout << "Группа изделий: " << productGroup << ", Марка изделия: " << productBrand
            << ", Дата приемки: " << receptionDate << ", Время ремонта: " << repairTime << endl;
    }
};

// Класс для узла бинарного дерева
class Node {
public:
    RepairReceipt data;
    Node* left;
    Node* right;

    // Конструктор
    Node(const RepairReceipt& receipt) : data(receipt), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева
class BinaryTree {
private:
    Node* root;

    // Рекурсивный метод для добавления узла в дерево
    Node* addNode(Node* root, const RepairReceipt& receipt) {
        if (root == nullptr) {
            return new Node(receipt);
        }
        if (receipt < root->data) {
            root->left = addNode(root->left, receipt);
        }
        else {
            root->right = addNode(root->right, receipt);
        }
        return root;
    }

    // Рекурсивный метод для поиска квитанции в дереве
    Node* findNode(Node* root, const RepairReceipt& receipt) {
        if (root == nullptr || root->data == receipt) {
            return root;
        }
        if (receipt < root->data) {
            return findNode(root->left, receipt);
        }
        return findNode(root->right, receipt);
    }

public:
    // Конструктор
    BinaryTree() : root(nullptr) {}

    // Метод добавления квитанции в дерево
    void addReceipt(const RepairReceipt& receipt) {
        root = addNode(root, receipt);
    }

    // Метод поиска квитанции в дереве
    Node* findReceipt(const RepairReceipt& receipt) {
        return findNode(root, receipt);
    }
};

int main() {
    // Создаем бинарное дерево
    BinaryTree tree;

    // Создаем несколько квитанций
    RepairReceipt receipt1("Телевизоры", "Samsung", "2024-05-01", "12:00");
    RepairReceipt receipt2("Радиоприемники", "Sony", "2024-04-25", "10:30");
    RepairReceipt receipt3("Телевизоры", "LG", "2024-04-30", "15:45");

    // Добавляем квитанции в дерево
    tree.addReceipt(receipt1);
    tree.addReceipt(receipt2);
    tree.addReceipt(receipt3);

    // Поиск квитанции в дереве
    RepairReceipt searchReceipt("Телевизоры", "Samsung", "2024-05-01", "12:00");
    Node* foundNode = tree.findReceipt(searchReceipt);
    if (foundNode) {
        cout << "Найдена квитанция:" << endl;
        foundNode->data.printReceiptInfo();
    }
    else {
        cout << "Квитанция не найдена." << endl;
    }

    return 0;
}
