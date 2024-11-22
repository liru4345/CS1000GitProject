#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readAndPrintFile(const std::string& filePath) {
    std::ifstream file(filePath); // Open the file
    if (file.is_open()) {
        std::string line;
        std::cout << "Contents of " << filePath << ":\n";
        while (std::getline(file, line)) { // Read file line by line
            std::cout << line << '\n';    // Print each line
        }
        file.close(); // Close the file
        std::cout << "-------------------\n";
    } else {
        std::cerr << "Error: Could not open file " << filePath << '\n';
    }
}

int main() {
    std::vector<std::string> fileNames; // Vector to store file names
    int fileCount;

    // Ask the user for the number of files
    std::cout << "Enter the number of text files to read: ";
    std::cin >> fileCount;

    // Get the file names from the user
    for (int i = 0; i < fileCount; ++i) {
        std::string fileName;
        std::cout << "Enter the name of file " << i + 1 << ": ";
        std::cin >> fileName;
        fileNames.push_back(fileName);
    }

    // Read and print the contents of each file
    for (const auto& fileName : fileNames) {
        readAndPrintFile(fileName);
    }

    return 0;
}