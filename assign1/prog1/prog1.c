#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char a;
	fp=fopen("first.txt","r");
	a=getc(fp);
	while(a!=EOF)
	{
		printf("%c",a);
		a=getc(fp);
	}
	fclose(fp);
}
