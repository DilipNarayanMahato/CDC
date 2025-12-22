%{
#include <stdio.h>
#include <stdlib.h> // for atoi
%}

%%

[0-9]+ {
    int num = atoi(yytext); // Convert matched text to integer
    if (num % 2 == 0)
        printf("%d is even\n", num);
    else
        printf("%d is odd\n", num);
}

. {
    printf("Invalid input: %s\n", yytext);
}

%%

int main() {
    printf("Enter a number: ");
    yylex(); // Call lexical analyzer
    return 0;
}

int yywrap() {
    return 1;
}
