#include <iostream>
#include <fstream>

int main() {

    std::string searchWord, temp;
    std::cout << "Enter word:" << std::endl;
    std::cin >> searchWord;

    std::ifstream words;
    words.open("C:\\Users\\user\\CLionProjects\\Skillbox_HW_19\\Task_1\\words.txt");

    int count = 0;
    while (!words.eof()) {
        words >> temp;
        if (temp == searchWord) count++;
    }
    std::cout << "Number repeat of word: " << count << std::endl;
    words.close();
    return 0;
}