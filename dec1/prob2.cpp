#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    char ch;
    int counter = 0;
    int position = 0;

    while (inputFile >> ch) {
        position++;
        if (ch == '(') {
            counter++;
        } else if (ch == ')') {
            counter--;
        }

        if (counter < 0) {
            std::cout << "Position: " << position << std::endl;
            return 0;
        }
    }

    std::cout << "Counter never went below zero." << std::endl;
    return 0;
}