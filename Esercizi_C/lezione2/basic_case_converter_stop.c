#include <stdio.h>
#include <ctype.h>

enum { MAIUSC = 1, MINUSC };

int main(void) {
    char letter = '\0';
    int choice = 0;

    printf("Enter a char: ");
    letter = getchar();

    if(!isalpha(letter)) return -1;

    do {
        printf("\nConvert to:\n1) Uppercase\n2) Lowercase\n-> ");
        scanf("%d", &choice);
    } while(choice != 1 && choice != 2);

    if(choice == MAIUSC) printf("res: %c\n", toupper(letter));
    else printf("res: %c\n", tolower(letter));
    
    return 0;
}