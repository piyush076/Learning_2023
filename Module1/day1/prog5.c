#include <stdio.h>

int bit_operations(int num, int oper_type) {
    switch (oper_type) {
        case 1: // Set 1st bit
            num |= 1;
            break;
        case 2: // Clear 31st bit
            num &= ~(1 << 31);
            break;
        case 3: // Toggle 16th bit
            num ^= 1 << 16;
            break;
        default:
            printf("Error: Invalid operation type!\n");
            return num;
    }

    return num;
}

int main() {
    int num, oper_type;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter operation type (1, 2, 3): ");
    scanf("%d", &oper_type);

    int result = bit_operations(num, oper_type);
    printf("Result: %d\n", result);

    return 0;
}
