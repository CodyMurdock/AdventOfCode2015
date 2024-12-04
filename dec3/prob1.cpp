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
    int x = 0, y = 0;
    visitedLocations.insert({x, y});

    char direction;
    while (inputFile >> direction) {
        switch (direction) {
            case '^': y++; break;
            case 'v': y--; break;
            case '<': x--; break;
            case '>': x++; break;
            default: break;
        }
        visitedLocations.insert({x, y});
    }

    inputFile.close();

    std::cout << "Number of locations visited at least once: " << visitedLocations.size() << std::endl;

    return 0;
}