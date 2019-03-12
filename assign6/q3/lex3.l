%{
	#include<stdio.h>
	
	int c = 0, words=0, lines = 0, letters = 0 , splchar = 0, n = 0;
%}

%%

\n 	{ lines ++;
	  words ++;
}
[\t ' ']  words ++;
[a-zA-Z] letters ++;
[0-9] 	n ++;
.	splchar;

%%
int main()
{
    yylex();
    printf ("Characters = %d \n", (letters + n+ splchar));
    printf ("Words = %d \n", words);
    printf ("Lines = %d \n", lines);
    return 0;
}
	
