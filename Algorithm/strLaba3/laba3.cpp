#include <iostream>
#include <fstream>

int calculateProductOfDigits(int number) {
    int product = 1;
    while (number != 0) {
        product *= number % 10;
        number /= 10;
    }
    return product;
}

void sortNumbersByProduct(std::ifstream& inputFile, std::ofstream& tempFile) {
    int number;
    bool inserted = false;

    while (inputFile >> number) {
        int product = calculateProductOfDigits(number);

        std::ifstream tempRead("temp.txt");
        std::ofstream tempWrite("temp2.txt");

        while (tempRead >> number) {
            if (calculateProductOfDigits(number) > product) {
                tempWrite << number << std::endl;
            }
            else {
                tempWrite << number << std::endl;
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            tempWrite << number << std::endl;
        }

        tempRead.close();
        tempWrite.close();

        remove("temp.txt");
        rename("temp2.txt", "temp.txt");
    }

    inputFile.close();
    tempFile.close();

    remove("input.txt");
    rename("temp.txt", "input.txt");
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream tempFile("temp.txt");

    sortNumbersByProduct(inputFile, tempFile);

    return 0;
}