#include<stdio.h>
#include<stdlib.h>

void main()
{
	int row, col , i , j, value;
	FILE *input , *output;
	input = fopen("input.txt","r");
	
	fscanf(input,"%d %d %d", &row, &col, &value);
	int matrix[row][col];
      	
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			matrix[i][j] = 0;
	
	while(!feof(input))
	{
		fscanf(input, "%d %d %d" , &i,&j,&value);
		matrix[i][j] =  value;
	}
	fclose(input);

	output = fopen("output.txt", "w");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			fprintf(output,"%d", matrix[i][j]);
		fprintf(output,"\n");
	}
	fclose(output);
}
	
	
