#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    char ch;
    int countOpen = 0;
    int countClose = 0;

    while (inputFile >> ch) {
        if (ch == '(') {
            countOpen++;
        } else if (ch == ')') {
            countClose++;
        }
    }

    inputFile.close();

    int result = countOpen - countClose;
    std::cout << "Result: " << result << std::endl;

    return 0;
}