#include <stdio.h>
#include <limits.h>

void findSmallestLargestDigits(int n, ...) {
    va_list args;
    va_start(args, n);

    int smallestDigit = INT_MAX;
    int largestDigit = INT_MIN;

    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);

        while (num != 0) {
            int digit = num % 10;

            if (digit < smallestDigit) {
                smallestDigit = digit;
            }

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            num /= 10;
        }
    }

    va_end(args);

    if (smallestDigit == INT_MAX || largestDigit == INT_MIN) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallestDigit);
        printf("Largest digit: %d\n", largestDigit);
    }
}

int main() {
    findSmallestLargestDigits(3, 8, 156, 123450);

    return 0;
}
