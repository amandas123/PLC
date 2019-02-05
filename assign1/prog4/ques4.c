#include<stdio.h>

int main()
{
	FILE *fp;
    	char ch;

	fp = fopen("ques4.txt", "a");
	do{
		scanf("%c",&ch);
		putc(ch,fp);
	}
    	while((int)ch!=10);
    
    	fclose(fp);

    	return 0;
}