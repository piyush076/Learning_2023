#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void swapFields(struct Student *s1, struct Student *s2) {
    // Swap name field
    char tempName[50];
    strcpy(tempName, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, tempName);

    // Swap rollNumber field
    int tempRollNumber = s1->rollNumber;
    s1->rollNumber = s2->rollNumber;
    s2->rollNumber = tempRollNumber;

    // Swap marks field
    float tempMarks = s1->marks;
    s1->marks = s2->marks;
    s2->marks = tempMarks;
}

int main() {
    struct Student student1 = {"John", 1, 90.5};
    struct Student student2 = {"Emma", 2, 87.2};

    printf("Before swapping:\n");
    printf("Student 1: %s, %d, %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2: %s, %d, %.2f\n", student2.name, student2.rollNumber, student2.marks);

    // Call the swapFields function
    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1: %s, %d, %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2: %s, %d, %.2f\n", student2.name, student2.rollNumber, student2.marks);

    return 0;
}
