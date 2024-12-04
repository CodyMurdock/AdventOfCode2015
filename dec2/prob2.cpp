#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inputFile("/home/cody/Git_Repos/FunPrograms/AdventOfCode2015/dec2/input.txt");
    std::string line;
    int totalRibbon = 0;
    int length = 0;
    int width = 0;
    int height = 0;
    if (!inputFile) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string lengthStr, widthStr, heightStr;

        if (std::getline(iss, lengthStr, 'x') &&
            std::getline(iss, widthStr, 'x') &&
            std::getline(iss, heightStr, 'x')) {
            length = std::stoi(lengthStr);
            width = std::stoi(widthStr);
            height = std::stoi(heightStr);

            // Use the variables length, width, and height as needed
            //std::cout << "Length: " << length << ", Width: " << width << ", Height: " << height << std::endl;
        }
        int smallestPerimeter = 2 * (length + width + height - std::max(std::max(length, width), height));
        int bow = length * width * height;
        totalRibbon += smallestPerimeter + bow;
        
    }

    inputFile.close();
    std::cout << "Total ribbon: " << totalRibbon << std::endl;
    return 0;
}