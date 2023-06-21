#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex readComplexNumber() {
    struct Complex num;

    printf("Enter the real part: ");
    scanf("%f", &num.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &num.imaginary);

    return num;
}

void writeComplexNumber(struct Complex num) {
    printf("Complex number: %.2f + %.2fi\n", num.real, num.imaginary);
}

struct Complex addComplexNumbers(struct Complex num1, struct Complex num2) {
    struct Complex result;

    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;

    return result;
}

struct Complex multiplyComplexNumbers(struct Complex num1, struct Complex num2) {
    struct Complex result;

    result.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    result.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);

    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    // Reading complex numbers
    printf("Reading Complex Number 1:\n");
    num1 = readComplexNumber();

    printf("\nReading Complex Number 2:\n");
    num2 = readComplexNumber();

    // Writing complex numbers
    printf("\nWriting Complex Number 1:\n");
    writeComplexNumber(num1);

    printf("\nWriting Complex Number 2:\n");
    writeComplexNumber(num2);

    // Adding complex numbers
    sum = addComplexNumbers(num1, num2);
    printf("\nSum of Complex Numbers:\n");
    writeComplexNumber(sum);

    // Multiplying complex numbers
    product = multiplyComplexNumbers(num1, num2);
    printf("\nProduct of Complex Numbers:\n");
    writeComplexNumber(product);

    return 0;
}
