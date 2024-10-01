#include <iostream>
#include <string>

using namespace std;

// ����� ��� ��������� � ����� ��������������� � ������
class RepairReceipt {
private:
    string productGroup;  // ������������ ������ �������
    string productBrand;  // ����� �������
    string receptionDate; // ���� �������
    string repairTime;    // ����� �������

public:
    // �����������
    RepairReceipt(const string& group, const string& brand, const string& date, const string& time)
        : productGroup(group), productBrand(brand), receptionDate(date), repairTime(time) {}

    // ���������� ��������� ���������
    bool operator<(const RepairReceipt& other) const {
        // ���������� �� ���� ������� (��������, ��� ����� ������ ���� ����� ������� ���������)
        return receptionDate < other.receptionDate;
    }

    // ����� ��� ������ ���������� � ���������
    void printReceiptInfo() const {
        cout << "������ �������: " << productGroup << ", ����� �������: " << productBrand
            << ", ���� �������: " << receptionDate << ", ����� �������: " << repairTime << endl;
    }
};

// ����� ��� ���� ��������� ������
class Node {
public:
    RepairReceipt data;
    Node* left;
    Node* right;

    // �����������
    Node(const RepairReceipt& receipt) : data(receipt), left(nullptr), right(nullptr) {}
};

// ����� ��������� ������
class BinaryTree {
private:
    Node* root;

    // ����������� ����� ��� ���������� ���� � ������
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

    // ����������� ����� ��� ������ ��������� � ������
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
    // �����������
    BinaryTree() : root(nullptr) {}

    // ����� ���������� ��������� � ������
    void addReceipt(const RepairReceipt& receipt) {
        root = addNode(root, receipt);
    }

    // ����� ������ ��������� � ������
    Node* findReceipt(const RepairReceipt& receipt) {
        return findNode(root, receipt);
    }
};

int main() {
    // ������� �������� ������
    BinaryTree tree;

    // ������� ��������� ���������
    RepairReceipt receipt1("����������", "Samsung", "2024-05-01", "12:00");
    RepairReceipt receipt2("��������������", "Sony", "2024-04-25", "10:30");
    RepairReceipt receipt3("����������", "LG", "2024-04-30", "15:45");

    // ��������� ��������� � ������
    tree.addReceipt(receipt1);
    tree.addReceipt(receipt2);
    tree.addReceipt(receipt3);

    // ����� ��������� � ������
    RepairReceipt searchReceipt("����������", "Samsung", "2024-05-01", "12:00");
    Node* foundNode = tree.findReceipt(searchReceipt);
    if (foundNode) {
        cout << "������� ���������:" << endl;
        foundNode->data.printReceiptInfo();
    }
    else {
        cout << "��������� �� �������." << endl;
    }

    return 0;
}
