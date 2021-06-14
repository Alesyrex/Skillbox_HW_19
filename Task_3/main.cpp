#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::string firstName,secondName,date;
    int sum = 0,salary,maxSalary = 0;
    std::string nameMaxSalary;

    std::ifstream bill;
    bill.open("C:\\files\\bill.txt");

    while(!bill.eof()){
        bill >> firstName >> secondName >> salary >> date;
        if (salary > maxSalary) {
            maxSalary = salary;
            nameMaxSalary = firstName + ' ' + secondName;
        }
        sum += salary;
    }
    std::cout << "Total sum: " << sum << std::endl;
    std::cout << "Maximum salary at " << nameMaxSalary << std::endl;
    bill.close();

    return 0;
}