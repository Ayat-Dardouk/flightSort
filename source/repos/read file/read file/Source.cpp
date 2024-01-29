#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("oimageFile.txt"); // Replace "example.txt" with your file name

    if (file.is_open()) {
        std::string line;

        // Read and print the file line by line
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
    }
    else {
        std::cout << "Unable to open the file" << std::endl;
    }

    return 0;
    g++ -o apply apply.cpp
        . / apply oimage.txt sharpen_kernel.txt output.txt


}
