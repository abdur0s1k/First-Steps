#include <iostream>
#include <string>
#include <memory>

// ��������� �������������� �����
struct Book {
    std::string title;
    std::string author;
    int year;

    Book(const std::string& t, const std::string& a, int y) : title(t), author(a), year(y) {}
};

// ����� ���� ������
template <typename T>
class Node {
public:
    T data;
    std::shared_ptr<Node<T>> next;

    Node(const T& value) : data(value), next(nullptr) {}
};

// ����� ������
template <typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> head;

public:
    // ���������� �������� � ����� ������
    void append(const T& value) {
        if (!head) {
            head = std::make_shared<Node<T>>(value);
        }
        else {
            std::shared_ptr<Node<T>> current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = std::make_shared<Node<T>>(value);
        }
    }

    // ����� ���������� � ������ � ������
    void displayBooksInfo() {
        std::shared_ptr<Node<T>> current = head;
        while (current) {
            std::cout << "Title: " << current->data.title << ", Author: " << current->data.author
                << ", Year: " << current->data.year << ", Age: " << calculateBookAge(current->data) << " years"
                << ", Days since publication: " << calculateBookAge(current->data) * 365 << " days" << std::endl;
            current = current->next;
        }
    }

private:
    // ���������� �������� �����
    int calculateBookAge(const Book& book) const {
        return 2024 - book.year; // ������������, ��� ������� ��� - 2024
    }

};

int main() {
    LinkedList<Book> bookList;

    // ���������� ���� � ������
    bookList.append(Book("Book1", "Author1", 2000));
    bookList.append(Book("Book2", "Author2", 2010));
    bookList.append(Book("Book3", "Author3", 1995));

    // ����� ���������� � ������ � ������
    bookList.displayBooksInfo();

    return 0;
}
