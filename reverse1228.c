#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

int getline(char line[], int maxline);

void reverse(char s[]);

void main()
{
    char line[MAXLINE];
    while(getline(line, MAXLINE)>0)
    {
        reverse(line);
        printf("%s", line);
    }
}

int getline(char line[], int maxline)
{
    int c, i,j=0;
    //for(i=0; ((c=getchar())!=EOF&&(c!='\n')); i++)
    for(i=0; ((c=getchar())!=EOF); i++)
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

/*void reverse(char s[])
{
    int i = 0;
    int j= 0;
    char temp[MAXLINE];
    bool _n_flag=false;
    while(s[i]!='\0')
    {
        i++;
    }
    i--;
    if(s[i]=='\n')
    {
        i--;
        _n_flag=true;
    }
    for(j=0;j<=i;j++)
    {
        temp[i-j]=s[j];
    }
    for(j=0;j<=i;j++)
    {
        s[j]=temp[j];
    }
    j++;
    if(_n_flag)
    {
            s[j]='\n';
            j++;
    }
    s[j]='\0';
}*/

void reverse(char line[])
{
    int i,j =0;
    char temp='\0';
    while (line[i]!='\0')
    {
        i++;
    }
    i--;
    if(line[i]=='\n'){i--; }
    while(j<i)
    {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        i--;
        j++;
    }


}


