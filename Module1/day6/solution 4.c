#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compareMarks(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;

    // Compare marks in descending order
    if (studentA->marks > studentB->marks) {
        return -1;
    } else if (studentA->marks < studentB->marks) {
        return 1;
    } else {
        return 0;
    }
}

void sortStudents(struct Student* students, int size) {
    // Sort the array of structures based on marks
    qsort(students, size, sizeof(struct Student), compareMarks);
}

void displayStudents(struct Student* students, int size) {
    printf("\nArray of Structures:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Rollno: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Declare an array of structures
    struct Student students[size];

    // Code to initialize the array of structures

    // Call the sortStudents function to sort the array of structures
    sortStudents(students, size);

    // Call the displayStudents function to display the sorted array
    displayStudents(students, size);

    return 0;
}
