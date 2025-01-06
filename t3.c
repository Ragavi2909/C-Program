#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// List of keywords
const char *keywords[] = {"int", "float", "if", "else", "while", "return", "char", "for", "void"};
int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

// Function to check if a word is a keyword
int isKeyword(const char *word) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    char operators[] = "+-*/%=<>";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *file;
    char filename[MAX], ch, buffer[MAX];
    int i = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    printf("\nLexical Analysis:\n");
    while ((ch = fgetc(file)) != EOF) {
        // Handle operators
        if (isOperator(ch)) {
            printf("Operator: %c\n", ch);
        }
        // Handle identifiers and keywords
        else if (isalnum(ch)) {
            buffer[i++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == ';' || ch == ',') && i > 0) {
            buffer[i] = '\0';
             i = 0;
            if (isKeyword(buffer)) {
                printf("Keyword: %s\n", buffer);
            } else {
                printf("Identifier: %s\n", buffer);
            }
        }
    }

    fclose(file);
    return 0;
}

