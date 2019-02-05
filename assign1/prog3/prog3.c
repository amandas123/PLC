#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp,*fp2;
	char ch;
	fp = fopen("first.txt","r");
	fp2 = fopen("file3.txt","w");
	ch = fgetc(fp);
	while(ch != EOF)
	{
		
		fputc(ch,fp2);
		ch = fgetc(fp);
	}	
	fclose(fp);
	fclose(fp2);
	return 0;
	
}
