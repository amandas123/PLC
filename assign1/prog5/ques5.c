#include<stdio.h>

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
    p = fopen("employee.txt", "a");
    
    printf("enter how many records you want to enter ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("Enter Name and Age:");
    scanf("%s %d", e.name, &e.age);
    fprintf(p,"%s %d", e.name, e.age);
    fprintf(p,"\n");
    
    }
    fclose(p);
  }
