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
} token_type;

// Lexeme structure
typedef struct {
    char lexeme[12]; // Assuming a maximum of 11 characters plus null terminator
    token_type type;
} lexeme;

// Global variables for lexeme list and index
lexeme* lexeme_list;
int lexeme_index = 0;

// Function to print an error message, free lexeme list, and exit
void printerror(const char* message) {
    fprintf(stderr, "Lexical Error: %s\n", message);
    free(lexeme_list);
    exit(EXIT_FAILURE);
}

// Function to print the lexeme table and token list
void printtokens() {
    printf("Lexeme Table:\n");
    for (int i = 0; i < lexeme_index; ++i) {
        printf("%s\t%d\n", lexeme_list[i].lexeme, lexeme_list[i].type);
    }
}

// Function to handle the lexeme analysis
lexeme* lexanalyzer(char* input) {
    // Initialize lexeme list
    lexeme_list = malloc(sizeof(lexeme) * 100); // Assuming a maximum of 100 lexemes

    // Your implementation goes here...

    // Example: Tokenize the input and add lexemes to lexeme_list
    // Example: Handle errors by calling printerror when necessary

    // Mark the end of the lexeme list
    lexeme_list[lexeme_index].type = -1; // Use -1 to indicate the end of the list

    // Call printerror or printtokens based on your logic
    // printerror("Some error message");
    // printtokens();

    // Return lexeme list
    return lexeme_list;
}

int main() {
    // Example usage
    char input[] = "var x, [3]; procedure func if <> ? problem : bueno y(2) := 4 * 8 % 11 end begin call do while > < == candy : read write <===>=-+.";
    lexeme* result = lexanalyzer(input);

    // Free the lexeme list after use
    free(result);

    return 0;
}