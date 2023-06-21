#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    const char* delim = " ";
    char* token;

    // Parse the input string and initialize the array of structures
    for (int i = 0; i < size; i++) {
        // Extract the rollno
        token = strtok((char*)input, delim);
        students[i].rollno = atoi(token);

        // Extract the name
        token = strtok(NULL, delim);
        strcpy(students[i].name, token);

        // Extract the marks
        token = strtok(NULL, delim);
        students[i].marks = atof(token);

        // Move to the next input
        input = strchr(input, '\0') + 1;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();  // Clear the input buffer

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline character

    // Call the parseString function to initialize the array of structures
    parseString(input, students, size);

    // Print the initialized array of structures
    printf("\nArray of Structures:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Rollno: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
