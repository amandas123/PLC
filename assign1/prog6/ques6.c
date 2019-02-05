#include<stdio.h>
#include<stdlib.h>
struct emp
{
    char name[10];
    int age;
};

void main()
{
    struct emp e;
    int n,i;
    FILE *p;
    p = fopen("employee.txt", "r");
    
    while(fscanf(p,"%s %d", e.name, &e.age)!=EOF)

    {
    printf("%s %d\n", e.name, e.age);

	}
    
    
    fclose(p);
    
}
