#include <iostream>
#include <string>

using namespace std;

class RepairReceipt {
private:
    string productGroup;
    string productBrand;
    string receptionDate;
    string repairTime;

public:
    RepairReceipt(const string& group, const string& brand, const string& date, const string& time)
        : productGroup(group), productBrand(brand), receptionDate(date), repairTime(time) {}

    bool operator==(const RepairReceipt& other) const {
        return productGroup == other.productGroup &&
            productBrand == other.productBrand &&
            receptionDate == other.receptionDate &&
            repairTime == other.repairTime;
    }

    bool operator<(const RepairReceipt& other) const {
        return receptionDate < other.receptionDate;
    }

    void printReceiptInfo() const {
        cout << "Группа изделий: " << productGroup << ", Марка изделия: " << productBrand
            << ", Дата приемки: " << receptionDate << ", Время ремонта: " << repairTime << endl;
    }
};

class Node {
public:
    RepairReceipt data;
    Node* left;
    Node* right;

    Node(const RepairReceipt& receipt) : data(receipt), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

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

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* root, const RepairReceipt& receipt) {
        if (root == nullptr) {
            return root;
        }
        if (receipt < root->data) {
            root->left = deleteNode(root->left, receipt);
        }
        else if (!(receipt < root->data) && !(root->data < receipt)) { // Исправлено условие
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        else {
            root->right = deleteNode(root->right, receipt);
        }
        return root;
    }



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
    BinaryTree() : root(nullptr) {}

    void addReceipt(const RepairReceipt& receipt) {
        root = addNode(root, receipt);
    }

    void deleteReceipt(const RepairReceipt& receipt) {
        root = deleteNode(root, receipt);
    }

    Node* findReceipt(const RepairReceipt& receipt) {
        return findNode(root, receipt);
    }
};

int main() {
    setlocale(0, "");
    BinaryTree tree;

    RepairReceipt receipt1("Телевизоры", "Samsung", "2024-05-01", "12:00");
    RepairReceipt receipt2("Радиоприемники", "Sony", "2024-04-25", "10:30");
    RepairReceipt receipt3("Телевизоры", "LG", "2024-04-30", "15:45");

    tree.addReceipt(receipt1);
    tree.addReceipt(receipt2);
    tree.addReceipt(receipt3);

    RepairReceipt searchReceipt("Телевизоры", "Samsung", "2024-05-01", "12:00");
    Node* foundNode = tree.findReceipt(searchReceipt);
    if (foundNode) {
        cout << "Найдена квитанция:" << endl;
        foundNode->data.printReceiptInfo();
    }
    else {
        cout << "Квитанция не найдена." << endl;
    }

    tree.deleteReceipt(receipt1); // Удаляем квитанцию receipt1

    return 0;
}

