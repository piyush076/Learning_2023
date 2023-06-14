#include <stdio.h>
#include <math.h>

void printExponent(double x) {
    int exponent = 0;
    
    // Get the exponent using frexp() function from math.h
    frexp(x, &exponent);
    
    // Convert exponent to hexadecimal
    printf("Exponent in Hex: 0x%X\n", exponent);
    
    // Convert exponent to binary
    printf("Exponent in Binary: 0b");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        int bit = (exponent >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
