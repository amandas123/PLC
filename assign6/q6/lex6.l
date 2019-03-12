%{
	#include <stdio.h>
	#include <ctype.h>
	int letters = 0;
%}

%%

. {
    if(isupper(yytext[0]))
    {
        printf("%c\n", yytext[0]);
        letters++;
    }
}

%%

int main()
{
    yylex();
    printf("No of capital letters = %d\n", letters);
}
