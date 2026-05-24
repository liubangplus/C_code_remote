#include <stdio.h>
#define MAXLINE 1000  /*maximum input line size*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*print longest input line*/
int main()
{
    int len;//current line length
    int max =0 ; //maximum length seen so far
    char line[MAXLINE];//current input line
    char longest[MAXLINE];//longest input saved here

    while((len=getline(line, MAXLINE))>0)
    {
        printf("%d, %s", len, line);
        if(len>max)
        {
            max=len;
            copy(longest, line);
        }
    }
    if(max>0)
    {
        printf("%s", longest);
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

void copy(char to[], char from[])
{
    int i=0;
    while(from[i]!='\0')
    {
        to[i]=from[i];
        i++;
    }
}
