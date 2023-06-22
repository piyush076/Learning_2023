#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *srcFile, *destFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open the source 
    srcFile = fopen("source.txt", "rb");
    if (srcFile == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    // Open the destination
    destFile = fopen("destination.txt", "wb");
    if (destFile == NULL) {
        printf("Unable to create destination file.\n");
        fclose(srcFile);
        return 1;
    }

    // Copy the contents 
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    // Close 
    fclose(srcFile);
    fclose(destFile);

    printf("File Copied Successfully.\n");

    return 0;
}
