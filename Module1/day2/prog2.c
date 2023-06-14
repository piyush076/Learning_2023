#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    unsigned char* byte_a = (unsigned char*)a;
    unsigned char* byte_b = (unsigned char*)b;
    
    for (size_t i = 0; i < size; i++) {
        unsigned char temp = byte_a[i];
        byte_a[i] = byte_b[i];
        byte_b[i] = temp;
    }
}

int main() {
    int num1 = 10;
    int num2 = 20;
    
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    
    swap(&num1, &num2, sizeof(int));
    
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    
    double pi = 3.14159;
    double e = 2.71828;
    
    printf("Before swap: pi = %lf, e = %lf\n", pi, e);
    
    swap(&pi, &e, sizeof(double));
    
    printf("After swap: pi = %lf, e = %lf\n", pi, e);
    
    return 0;
}
