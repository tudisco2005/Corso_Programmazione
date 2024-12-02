#include <stdio.h>
#include <ctype.h>

int main(void) {
    char letter = '\0';

    printf("Enter a char: ");
    letter = getchar();

    if(isalpha(letter)) {
        printf("res: %c\n", toupper(letter));
    } else printf("res: %c\n", letter);

    return 0;
}