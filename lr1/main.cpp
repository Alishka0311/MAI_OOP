#include <iostream>
#include <string>
#include "include/intToBinaryArray.h"

int main() {
    int number; 
    int binaryArray[32];
    std::string tmp;
    while (true) {
        bool flag = true;
        std::cout << "number: ";
        std::cin >> tmp;
        for (int i = 0; i < tmp.length(); ++i){
            if (!std::isdigit(tmp[i])){
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        number = std::stoi(tmp);
        break;
    }

    intToBinaryArray(number, binaryArray);

    for (int i = 0; i < 32; ++i) {
        std::cout << binaryArray[i];
    }
    std::cout << std::endl;

    return 0;
}