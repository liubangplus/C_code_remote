#include <stdio.h>

#define MAXLENGTH 1000
#define PRINT_LENGTH 80

int getline(char line[], int maxline);

int main()
{
    char line[MAXLENGTH];
    int c;

    while((c= getline(line, MAXLENGTH))>0)
    {
        if(c>PRINT_LENGTH)
        {
            printf("%s", line);
        }
    }

    return 0;
}


int getline(char line[], int maxline)
{
    int c, i,j=0;
    for(i=0; ((c=getchar())!=EOF&&(c!='\n')); i++)
    {
        if(i<maxline-2)
        {
            line[i]=c;
            j++;
        }
    }
    if(c=='\n')
    {
       line[i]=c;
       i++;
       j++;
    }
    line[j]='\0';
    return i;
}
