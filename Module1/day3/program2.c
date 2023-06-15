#include <stdio.h>

void printBits(int num) {
    unsigned int mask = 1 << 31; // Start with the leftmost bit
    
    for (int i = 0; i < 32; i++) {
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
        
        mask >>= 1; // Shift the mask to the right by one bit
    }
    
    printf("\n");
}

int main() {
    int num;
    
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);
    
    printf("Bits representation: ");
    printBits(num);
    
    return 0;
}
