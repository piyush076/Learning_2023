#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

void calculateVolumeAndSurfaceArea(struct Box* box) {
    double volume = box->length * box->width * box->height;
    double surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);

    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box box = {2.5, 3.7, 4.1};
    struct Box* boxPtr = &box;

    // Accessing members using (*) asterisk or indirection operator and (.) dot operator
    printf("Using (*) asterisk and (.) dot operator:\n");
    printf("Length: %.2f\n", (*boxPtr).length);
    printf("Width: %.2f\n", (*boxPtr).width);
    printf("Height: %.2f\n", (*boxPtr).height);

    // Accessing members using (->) Arrow operator
    printf("Using (->) arrow operator with pointer:\n");
    printf("Length: %.2f\n", boxPtr->length);
    printf("Width: %.2f\n", boxPtr->width);
    printf("Height: %.2f\n", boxPtr->height);

    // Accessing members using (->) Arrow operator with dot representation
    printf("Using (->) arrow operator with dot representation:\n");
    printf("Length: %.2f\n", boxPtr->length);
    printf("Width: %.2f\n", boxPtr->width);
    printf("Height: %.2f\n", boxPtr->height);

    // Calculate volume and surface area using structure pointer
    printf("Calculating volume and surface area using structure pointer:\n");
    calculateVolumeAndSurfaceArea(boxPtr);

    return 0;
}
