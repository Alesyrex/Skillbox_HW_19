#include <iostream>
#include <fstream>
#include <string>

int sector_Calculation(int sector, int spinning, int* array) {
    if (sector + spinning > 13) {
        if ((sector + spinning) % 13 != 0)
            return array[(sector + spinning) % 13 - 1];
        else return array[(sector + spinning) % 13 + 12];
    } else return array[spinning + sector - 1];
}

int main() {

    int spinningTop,tempSector,experts = 0,spectators = 0;
    char buffer[50];
    int sector = 1;
    int allSectors[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    std::string answerExperts,pathQuestion,pathAnswer, temp;

    for (int count = 1; count <= 13 ; count++) {
        std::cout << "Spin the top! (enter sector offset):";
        std::cin >> spinningTop;

        sector = sector_Calculation(sector,spinningTop,allSectors);
        while (sector == 0) {
            tempSector++;
            sector = sector_Calculation(tempSector,spinningTop,allSectors);
        }
        tempSector = sector;
        pathQuestion = "C:\\files\\4GK\\Question-" + std::to_string(sector) + ".txt";
        pathAnswer = "C:\\files\\4GK\\Answer-" + std::to_string(sector) + ".txt";
        std::cout << "Sector #" << sector << std::endl;
        allSectors[sector - 1] = 0;

        std::ifstream question;
        question.open(pathQuestion,std::ios::binary);
        int counter = 0;
        while(!question.eof()){
            question.read(buffer, sizeof(buffer) - 1);
            counter = question.gcount();
            buffer[counter] = 0;
            std::cout << buffer;
        }
        std::cout << std::endl;
        question.close();

        std::cout << "Your answer: ";
        std::cin >> answerExperts;

        std::ifstream answer;
        answer.open(pathAnswer);
        answer >> temp;
        if (answerExperts == temp) {
            std::cout << "Right!" << std::endl;
            experts++;
        }
        else {
            std::cout << "Wrong!" << std::endl;
            spectators++;
        }
        answer.close();

        if (experts == 6) {
            std::cout << "Experts wins!!!";
            return 0;
        }
        if (spectators == 6) {
            std::cout << "Spectators wins!!!";
            return 0;
        }
    }
    return 0;
}
