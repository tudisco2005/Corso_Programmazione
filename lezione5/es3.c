/*
Calcolatrice con modifica degli operandi (implementazione con funzioni).
Tempo: 15 min.
(Come nell’Esercizio 2, ma spezzando il programma in funzioni.
*/

#include <stdio.h>

enum {EXIT, EDIT, SUM, DIFF, MULTIPLY, DIVISION};

double sum(double a, double b) {
    return a+b;
}

double diff(double a, double b) {
    return a-b;
}

double multiply(double a, double b) {
    return a*b;
}

double division(double a, double b) {
    return a/b;
}

int menu(int *entered_nums, int *ask_again) {
    char choice_char;
    int choice_int;

    do {
        printf("\nSelect an operation:\n0) Exit\n1) Enter/Edit the numbers\n2) Sum\n3) Diff\n4) Multiply\n5) Division\n-> ");
        choice_char = getchar();
        choice_int = (int) choice_char - 48;
        *ask_again = 0;

        if (*entered_nums == 0 && choice_int >= SUM) {
            printf("Before the operations enter the numbers\n");
            *ask_again = 1;
        }
        if (choice_int < EXIT || choice_int > DIVISION) printf("Operation not valid, retry\n");
        else while(getchar() != '\n');
    } while(choice_int < EXIT || choice_int > DIVISION || *ask_again);
    
    return choice_int;
}

int main() {
    double num1, num2;
    int entered_nums = 0, ask_again = 0;
    
    while(1) {
        switch (menu(&entered_nums, &ask_again)) {
            case EDIT:
                printf("\nChange the value %lf to: ", num1);
                scanf("%lf", &num1);
                printf("Change the value %lf to: ", num2);
                scanf("%lf", &num2);
                entered_nums = 1;
                while(getchar() != '\n');
                break;
            case SUM:
                printf("SUM: %lf + %lf = %lf\n", num1, num2, sum(num1,num2));
                break;
            case DIFF:
                printf("Diff: %lf - %lf = %lf\n", num1, num2, diff(num1,num2));
                break;
            case MULTIPLY:
                printf("Multiply: %lf * %lf = %lf\n", num1, num2, multiply(num1,num2));
                break;
            case DIVISION:
                if (num2 == 0) printf("Error, Division by zero\n");
                else printf("Division: %lf / %lf = %lf\n", num1, num2, division(num1,num2));
                break;
            
            case EXIT:
                return 0;
        }
        printf("\n");
    }

    return 0;
}