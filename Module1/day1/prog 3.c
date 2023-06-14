#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float physics, math, chemistry;
    
    printf("Enter Roll No: ");
    scanf("%d", &rollNo);
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Marks (Physics Math Chemistry): ");
    scanf("%f %f %f", &physics, &math, &chemistry);
    
    float total = physics + math + chemistry;
    float percentage = total / 3.0;
    
    printf("\n----- Student Summary -----\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics: %.2f\n", physics);
    printf("Math: %.2f\n", math);
    printf("Chemistry: %.2f\n", chemistry);
    printf("Total Marks: %.2f\n", total);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
