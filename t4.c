#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Function to print the contents of a file
void printFileContents(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s' to display contents.\n", filename);
        perror("Reason");
        return;
    }

    printf("\nContents of %s:\n", filename);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    putchar('\n');
    fclose(file);
}

// Function to perform Run-Length Encoding (RLE) compression
void compressFile(const char* inputFile, const char* outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL) {
        printf("Error: Could not open input file '%s'.\n", inputFile);
        perror("Reason");
        return;
    }

    if (out == NULL) {
        printf("Error: Could not create output file '%s'.\n", outputFile);
        perror("Reason");
        fclose(in);
        return;
    }

    char current, prev;
    int count = 1;

    prev = fgetc(in);
    if (prev == EOF) {
        printf("Input file is empty.\n");
        fclose(in);
        fclose(out);
        return;
    }

    while ((current = fgetc(in)) != EOF) {
        if (current == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev, count);
            prev = current;
            count = 1;
        }
    }

    fprintf(out, "%c%d", prev, count);

    fclose(in);
    fclose(out);

    printf("File compressed successfully to %s.\n", outputFile);
    printFileContents(outputFile); // Print contents of the compressed file
}

// Function to perform Run-Length Encoding (RLE) decompression
void decompressFile(const char* inputFile, const char* outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL) {
        printf("Error: Could not open input file '%s'.\n", inputFile);
        perror("Reason");
        return;
    }

    if (out == NULL) {
        printf("Error: Could not create output file '%s'.\n", outputFile);
        perror("Reason");
        fclose(in);
        return;
    }

    char ch;
    int count;

    while (fscanf(in, "%c%d", &ch, &count) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("File decompressed successfully to %s.\n", outputFile);
    printFileContents(outputFile); // Print contents of the decompressed file
}

// Main function
int main(void) {
    int choice;
    char inputFile[50], outputFile[50];

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Compress a file\n");
        printf("2. Decompress a file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the input filename: ");
                scanf("%s", inputFile);
                printf("Enter the output filename: ");
                scanf("%s", outputFile);
                compressFile(inputFile, outputFile);
                break;
            case 2:
                printf("Enter the input filename: ");
                scanf("%s", inputFile);
                printf("Enter the output filename: ");
                scanf("%s", outputFile);
                decompressFile(inputFile, outputFile);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}