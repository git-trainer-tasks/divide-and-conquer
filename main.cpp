#include "filter.h"

#include <fstream>
#include <iostream>
#include <string>

void printUsage() {
    std::cout << "Usage: ./log-filter <level> <file>" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printUsage();
        return 1;
    }

    std::string level = argv[1];
    std::string fileName = argv[2];

    std::ifstream file(fileName.c_str());

    if (!file) {
        std::cout << "Cannot open file" << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (matchesLevel(line, level)) {
            std::cout << line << std::endl;
        }
    }

    return 0;
}
