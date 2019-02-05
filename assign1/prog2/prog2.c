#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int character=0,space=0,tab=0,newline=0;
	fp=fopen("text2.txt","r");
	
	while(ch != EOF)
	{
		ch = fgetc(fp);
		if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' )
			character++;
		if(ch==' ')
			space++;
		if(ch=='\t')
			tab++;
		if(ch=='\n')
			newline++;
		
	}	
	printf("No. of character %d\n",character);
	printf("No. of space %d\n",space);
	printf("No. of tab %d\n",tab);
	printf("No. of newline %d\n",newline);
	
	
	fclose(fp);
	return 0;
	
}
