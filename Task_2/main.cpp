#include <iostream>
#include <fstream>
#include <string>

int main() {

    char buffer[20];
    std::string way;
    std::cout << "Specify the path to the file (C:\\folder\\file.txt):" << std::endl;
    std::getline(std::cin,way);

    std::ifstream file;
    file.open(way,std::ios::binary);
    while (!file.is_open()) {
        std::cout << "Incorrect the path! Specify the path to the file:";
        std::getline(std::cin,way);
        file.open(way,std::ios::binary);
    }
    int count = 0;
    while(!file.eof()){
        file.read(buffer, sizeof(buffer) - 1);
        count = file.gcount();
        buffer[count] = 0;
        std::cout << buffer;
    }
    file.close();
    return 0;
}