%{
    int p=0;
    int n=0;
    int positivefractions=0;
    int negativefractions=0;
%}

DIGIT [0-9]
%%

\+?{DIGIT}+                              p++;
-{DIGIT}+                                n++;

\+?{DIGIT}*\.{DIGIT}+            positivefractions++;
-{DIGIT}*\.{DIGIT}+                negativefractions++;
. ;    
%%

int main()
{
    yylex();
    printf("\nNo. of positive numbers: %d",p);
    printf("\nNo. of Negative numbers: %d",n);
    printf("\nNo. of Positive fractions: %d",positivefractions);
    printf("\nNo. of Negative fractions: %d\n",negativefractions);
}
	
