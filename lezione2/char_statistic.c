#include <stdio.h>
#include <ctype.h>

int main(void) {
    char letter = '\0';
    int choice = 0;

    while(1) {
        printf("\nEnter a char: ");
        letter = getchar();

        if (letter == '\n') return 0;

        if(isalpha(letter)) printf("The char entered is alphanumeric\n");
        else printf("The char entered is not alphanumeric\n");

        if(isupper(letter)) printf("The char entered is uppercase\n");
        else printf("The char entered is lowercase\n");
        getchar();
    }
}