#include <stdio.h>

int findLargestNumber(int num) {
    int largestNum = 0;
    int divisor = 1;

    while (divisor <= 1000) {
        int truncatedNum = (num / divisor / 10) * divisor + (num % divisor);

        if (truncatedNum > largestNum) {
            largestNum = truncatedNum;
        }

        divisor *= 10;
    }

    return largestNum;
}

int main() {
    int num = 5872;
    int largestNum = findLargestNumber(num);

    printf("Largest number by deleting a single digit from %d: %d\n", num, largestNum);

    return 0;
}
