#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(struct Student* students, int size, const char* name) {
    int found = 0;
    printf("Search Results:\n");
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Rollno: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
        }
    }

    if (!found) {
        printf("No student found with the name '%s'\n", name);
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array of structures
    struct Student* students = malloc(size * sizeof(struct Student));

    // Code to initialize the array of structures

    // Search operation based on name
    char searchName[20];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    searchStudentByName(students, size, searchName);

    // Free dynamically allocated memory
    free(students);

    return 0;
}
