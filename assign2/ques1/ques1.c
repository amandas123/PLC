#include "stdio.h"
#include "stdlib.h"
void bubble_sort(int[], int);
void swap(int*, int*);
#define MAX 10
void main()
{
	FILE *source, *target;
	
	// (a) Randomly generate 10 numbers from the range 1-50 and store them into a file named “source.txt”.
	source = fopen("source.txt", "w");
	for(int i = 0; i < MAX; i++)
	{
		fprintf(source, "%d\n", rand() % 50);
	}
	fclose(source);
	
	
	// (b) Store the numbers into an array from the file “source.txt” and sort it using any sorting algorithm.
	int numbers[MAX], i = 0;
	source = fopen("source.txt", "r");
	while(!feof(source) && i < MAX)
	{
		fscanf(source, "%d", &numbers[i]);
		i++;
	}
	fclose(source);
	bubble_sort(numbers, MAX);
	
	// (c)Copy the sorted array into a file named “target.txt”.
	target = fopen("target.txt", "w");
	for(i = 0; i < MAX; i++)
	{
		fprintf(target, "%d\n", numbers[i]);
	}
	fclose(target);
}

void bubble_sort(int arr[], int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - i - 1; j++)
			if(arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
} 

