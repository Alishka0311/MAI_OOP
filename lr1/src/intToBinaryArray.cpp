#include "../include/intToBinaryArray.h"

void intToBinaryArray(int n, int binaryArray[32]) {
    for (int i = 0; i < 32; ++i) {
        binaryArray[31 - i] = (n >> i) & 1; 
    }
}