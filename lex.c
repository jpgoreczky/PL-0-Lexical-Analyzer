#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Token types enumeration
typedef enum {
skipsym = 1, identsym, numbersym, plussym, minussym,
multsym, slashsym, fisym, eqsym, neqsym, lessym, leqsym,
gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
periodsym, becomessym, beginsym, endsym, ifsym, thensym,
whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
readsym , elsesym
} tokenType;

// Lexeme structure
typedef struct {
    char varName[12]; // Assuming a maximum of 11 characters plus null terminator
    tokenType tokenType;
    int numVal;
    int errorType;
} lexeme;

// Global variables
lexeme* lexemeList;
int lexemeIndex = 0;
char * reservedWords[] = {"begin", "end", "if", "then", "while", 
                        "do", "call", "const", "var", "procedure", "write", "read", "else"};
char specialSym[] = {'+', '-', '*', '/', '(', ')', '=', ',' , '.', '<', '>', ';' , ':'};

// Print an error message, free lexeme list, and exit
void printError(lexeme* lexemeList, int size) {
    for (int i = 0; i < size; i++) {
        // if i is a number
        if (lexemeList[i].tokenType == 3) {
            switch (lexemeList[i].errorType)
            {
            case 1: // Number too long
                printf("Number too long.");
                break;
            case 2: // Name Too Long
                printf("Name too long.");
                break;
            case 3: // Invalid Symbols
                printf("Invalid symbols.");
                break;
            }
        } else { // i is not a number
            switch (lexemeList[i].errorType)
            {
            case 1: // Number too long
                printf("Number too long.");
                break;
            case 2: // Name Too Long
                printf("Name too long.");
                break;
            case 3: // Invalid Symbols
                printf("Invalid symbols.");
                break;
            }
        }
    }
    
}

// Print the lexeme table and token list
void printTokens() {
    printf("Lexeme Table:\n");
    for (int i = 0; i < lexemeIndex; ++i) {
        printf("%s\t%d\n", lexemeList[i].varName, lexemeList[i].type);
    }
}

// Print Source Program
void printSrc(FILE* fp) {
    printf("Source Program:\n");
    char input;

    fseek(fp, 0, SEEK_SET);
    while ((input = fgetc(fp)) != EOF) {
        putchar(input);
    }
}

// Function to handle the lexeme analysis
lexeme* lexAnalyzer(FILE *fp) {
    // Initialize lexeme list
    lexemeList = malloc(sizeof(lexeme) * 100); // Assuming a maximum of 100 lexemes
    

    // Example: Tokenize the input and add lexemes to lexeme_list
    // Example: Handle errors by calling printerror when necessary

    // Mark the end of the lexeme list
    lexemeList[lexemeIndex].type = -1; // Use -1 to indicate the end of the list

    // Call printerror or printtokens based on your logic
    // printerror("Some error message");
    // printtokens();

    // Return lexeme list
    return lexemeList;
}

int main(int argc, char **argv) {
    FILE *fp;
    fp = fopen(argv[1], "rb");
    printSrc(fp);
    fclose(fp);

    fp = fopen(argv[1], "r");

    // Lexical Analyzer
    lexeme* result = lexAnalyzer(fp);

    // Free the lexeme list after use
    free(result);

    // CLose file
    fclose(fp);

    return 0;
}