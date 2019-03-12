#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	q_A, q_B, q_C, q_D
} states;

states transition(states current, char input, FILE *fpw)
{
	states res = 0;
	switch(current)
	{
		case q_A:
			if(input == '1')
			{
				printf("--%c-->(q_B)", input);
				fprintf(fpw, "--%c-->(q_B)", input);
				res = q_B;
			}
			else if(input == '0')
			{
				printf("--%c-->(q_D)", input);
				fprintf(fpw, "--%c-->(q_D)", input);
				res = q_D;
			}
			return res;
		break;
		
		case q_B:
			if(input == '1')
			{
				printf("--%c-->(q_A)", input);
				fprintf(fpw,"--%c-->(q_A)", input);
				res = q_A;
			}
			else if(input == '0')
			{
				printf("--%c-->(q_C)", input);
				fprintf(fpw, "--%c-->(q_C)", input);
				res = q_C;
			}
			return res;
		break;

		case q_C:
			if(input == '1')
			{
				printf("--%c-->(q_D)", input);
				fprintf(fpw, "--%c-->(q_D)", input);
				res = q_D;
			}
			else if(input == '0')
			{
				printf("--%c-->(q_B)", input);
				fprintf(fpw, "--%c-->(q_B)", input);
				res = q_B;
			}
			return res;
		break;

		case q_D:
			if(input == '1')
			{
				printf("--%c-->(q_C)", input);
				fprintf(fpw, "--%c-->(q_C)", input);
				res = q_C;
			}
			else if(input == '0')
			{
				printf("--%c-->(q_A)", input);
				fprintf(fpw, "--%c-->(q_A)", input);
				res = q_A;
			}
			return res;
		break;
	}
}

void main()
{
	FILE *fp, *fpw;
	char ch;
	int i = 1;
	states current;
	current = 0;
	fp = fopen("input1.txt", "r");
	fpw = fopen("output1.txt", "w");
	printf("(q_A)");
	fprintf(fpw, "(q_A)");
	ch = getc(fp);
	while(ch != EOF)
	{	
		if(i == 1)
			current = transition(q_A, ch, fpw);
		else
			current = transition(current, ch, fpw);	
		ch = getc(fp);
		i++;
	}
	printf("\n");
	fclose(fp);
	fclose(fpw);
}
