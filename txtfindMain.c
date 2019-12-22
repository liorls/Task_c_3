#include <stdio.h>
#include "txtfind.h"
#include <string.h>
#include <stdlib.h>

int main(){

    char word[WORD];
    char option;
    printf("\nSelect a porogrom from the list:");
    printf("\na: Prints all lines in the text containing the string");
    printf("\nb: Prints all words in a text similar to a string until you omit one letter");
    printf("\nPlease enter your selection: ");

    char line[LINE];
    while((option != 'a') && (option != 'b')){
    
    if (fgets(line, sizeof line, stdin) == NULL) {
        printf("\nInput error.\n");
        exit(1);        
    }

    option = line[0];
    printf("\noption?: %c\n", option);

    getWord(word);
    option = getchar();

    switch (option)
    {
    case 'a':
        printf("Prints all lines in the text containing the string'%s':\n\n", word);
        print_lines(word);
        break;
    case 'b':
        printf("Prints all words in a text similar to a string until you omit one letter:\n", word);
        print_similar_words(word);
        break;

        if (option != 'a' && option != 'b')
        {
            printf("\n%c is not an option, Try again\n", option);
        }
    }
    return 0;
}
}