#include <iostream>
#include <fstream>
#include <string>

int main() {

    char buffer[4];
    std::string way;
    std::cout << "Specify the path to the file (C:\\folder\\file.png):" << std::endl;
    std::getline(std::cin,way);

    if (way.substr(way.length()-4) != ".png" && way.substr(way.length()-4) != ".PNG") {
        std::cout << "The file format is not PNG";
        return 0;
    }
    else {
        std::ifstream pict;
        pict.open(way,std::ios::binary);

        pict.read(buffer,4);
        if (buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') {
            std::cout << "Correct format file!" << std::endl;
        }
        else std::cout << "The file format isn't PNG";
        pict.close();
    }
    return 0;
}