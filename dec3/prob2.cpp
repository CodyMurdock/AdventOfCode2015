#include <iostream>
#include <fstream>
#include <set>
#include <utility>

int main() {
    std::ifstream inputFile("/home/cody/Git_Repos/FunPrograms/AdventOfCode2015/dec3/input.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::set<std::pair<int, int>> visitedLocations;
    int x1 = 0, y1 = 0; // Coordinates for the first entity
    int x2 = 0, y2 = 0; // Coordinates for the second entity
    visitedLocations.insert({x1, y1});
    visitedLocations.insert({x2, y2});

    char direction;
    bool isFirstEntityTurn = true;
    while (inputFile >> direction) {
        if (isFirstEntityTurn) {
            switch (direction) {
                case '^': y1++; break;
                case 'v': y1--; break;
                case '<': x1--; break;
                case '>': x1++; break;
                default: break;
            }
            visitedLocations.insert({x1, y1});
        } else {
            switch (direction) {
                case '^': y2++; break;
                case 'v': y2--; break;
                case '<': x2--; break;
                case '>': x2++; break;
                default: break;
            }
            visitedLocations.insert({x2, y2});
        }
        isFirstEntityTurn = !isFirstEntityTurn; // Alternate turns
    }

    inputFile.close();

    std::cout << "Number of locations visited at least once: " << visitedLocations.size() << std::endl;

    return 0;
}