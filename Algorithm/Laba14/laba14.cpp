#include <iostream> 
#include <string> 
using namespace std;

struct BankClient {
    string fullName;
    int accountNumber;
    double amountOnAccount;
    double interestRate;
    BankClient* next;
};

class BankClientList {
private:
    BankClient* firstClient;
public:
    BankClientList() {
        firstClient = nullptr;
    }

    void addClient(string fullName, int accountNumber, double amountOnAccount, double interestRate) {
        BankClient* newClient = new BankClient;
        newClient->fullName = fullName;
        newClient->accountNumber = accountNumber;
        newClient->amountOnAccount = amountOnAccount;
        newClient->interestRate = interestRate;

        if (firstClient == nullptr) {
            firstClient = newClient;
            newClient->next = firstClient;
        }
        else {
            BankClient* current = firstClient;
            while (current->next != firstClient) {
                current = current->next;
            }
            current->next = newClient;
            newClient->next = firstClient;
        }
    }

    void calculateAndPrintAmountAfterInterest() {
        BankClient* current = firstClient;
        do {
            cout << "Amount after interest for " << current->fullName << ": " << current->amountOnAccount * (1 + current->interestRate / 100) << endl;
            current = current->next;
        } while (current != firstClient);
    }

    void printAllClients() {
        BankClient* current = firstClient;
        do {
            cout << "Full name: " << current->fullName << ", Account number: " << current->accountNumber << ", Amount on account: " << current->amountOnAccount << ", Interest rate: " << current->interestRate << endl;
            current = current->next;
        } while (current != firstClient);
    }

    void modifyClientAmount(int accountNumber, double newAmount) {
        BankClient* current = firstClient;
        do {
            if (current->accountNumber == accountNumber) {
                current->amountOnAccount = newAmount;
                break;
            }
            current = current->next;
        } while (current != firstClient);
    }

    void deleteClient(int accountNumber) {
        BankClient* prev = firstClient;
        BankClient* current = firstClient->next;

        if (prev->accountNumber == accountNumber) {
            while (prev->next != firstClient) {
                prev = prev->next;
            }
            prev->next = current;
            delete firstClient;
            firstClient = current;
        }
        else {
            while (current != firstClient) {
                if (current->accountNumber == accountNumber) {
                    prev->next = current->next;
                    delete current;
                    break;
                }
                prev = prev->next;
                current = current->next;
            }
        }
    }

    void printSingleClient(int accountNumber) {
        BankClient* current = firstClient;
        do {
            if (current->accountNumber == accountNumber) {
                cout << "Full name: " << current->fullName << ", Account number: " << current->accountNumber << ", Amount on account: " << current->amountOnAccount << ", Interest rate: " << current->interestRate << endl;
                break;
            }
            current = current->next;
        } while (current != firstClient);
    }

    int countClients() {
        int count = 0;
        BankClient* current = firstClient;
        do {
            count++;
            current = current->next;
        } while (current != firstClient);
        return count;
    }
};

int main() {
    BankClientList clientList;
    clientList.addClient("Ivanov Ivan Ivanovich", 12345, 1000.0, 5.0);
    clientList.addClient("Petrov Petr Petrovich", 54321, 2000.0, 3.0);

    clientList.calculateAndPrintAmountAfterInterest();

    clientList.printAllClients();

    clientList.modifyClientAmount(12345, 1500.0);

    clientList.deleteClient(54321);

    clientList.printSingleClient(12345);

    cout << "Total number of clients: " << clientList.countClients() << endl;

    return 0;
}