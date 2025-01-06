#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File created successfully.\n");
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    char buffer[256];
    printf("Enter text to write to the file: ");
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(file, "%s", buffer);
    printf("Data written successfully.\n");
    fclose(file);
}

void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }
    char buffer[256];
    printf("Enter text to append to the file: ");
    fgets(buffer, sizeof(buffer), stdin);
    fprintf(file, "%s", buffer);
    printf("Data appended successfully.\n");
    fclose(file);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    char ch;
    printf("File contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

int main() {
    char filename[100];
    char choice;

    printf("Enter the name of the file: ");
    scanf("%99s", filename);
    getchar(); // Consume the newline character left by scanf

    printf("Choose an operation: \n");
    printf("r - Read the file\n");
    printf("w - Write to the file\n");
    printf("a - Append to the file\n");
    printf("c - Create a new file\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);
    getchar(); // Consume the newline character left by scanf

    switch (choice) {
        case 'r':
            readFile(filename);
            break;
        case 'w':
            writeFile(filename);
            break;
        case 'a':
            appendFile(filename);
            break;
        case 'c':
            createFile(filename);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}