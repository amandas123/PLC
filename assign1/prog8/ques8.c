#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp,*fp2;
    int p;
    
            fp=fopen("ques8.txt","r");
            fp2=fopen("ques8out.txt","w");   

            while((p=getc(fp))!=EOF)
            {

                fputc(p,fp2);
                if (p==32) 
                    {
                              while((p=getc(fp))==32)
                              {
                              }
                    fputc(p,fp2);
                    }
            }

fclose(fp);
fclose(fp2);
return 1;
}
