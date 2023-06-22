#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void convertToUpper(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void convertToLower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void convertToSentenceCase(char *str) {
    int isFirstChar = 1;
    while (*str) {
        if (isFirstChar) {
            *str = toupper(*str);
            isFirstChar = 0;
        } else {
            *str = tolower(*str);
        }

        if (*str == '.' || *str == '?' || *str == '!') {
            isFirstChar = 1;
        }

        str++;
    }
}

void copyFileWithCase(const char *srcFile, const char *destFile, char option) {
    FILE *src, *dest;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    src = fopen(srcFile, "r");
    if (src == NULL) {
        printf("Unable to open source file.\n");
        return;
    }

    dest = fopen(destFile, "w");
    if (dest == NULL) {
        printf("Unable to create destination file.\n");
        fclose(src);
        return;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        if (option == 'u') {
            convertToUpper(buffer);
        } else if (option == 'l') {
            convertToLower(buffer);
        } else if (option == 's') {
            convertToSentenceCase(buffer);
        }
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully with case option '%c'.\n", option);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <sourceFile> <destFile>\n");
        return 1;
    }

    char option = 'n';
    if (argc > 3) {
        option = argv[1][1];
    }

    char *srcFile = argv[argc - 2];
    char *destFile = argv[argc - 1];

    copyFileWithCase(srcFile, destFile, option);

    return 0;
}
