#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int remove_(char line[]);

int main()
{
    char line[MAXLENGTH];

    while((getline(line, MAXLENGTH))>0)
    {
        if(remove_(line)>0)
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

int remove_(char s[])
{
    int i;
    while(s[i]!='\n')           //find newline character
    {
        i++;
    }
    i--;                        //back off from '\n'
/* 这个函数将从后往前检查空格或制表符，直到它找到一个不是空格
或者制表符的字符可以让它继续倒退即（i<0）为止。如果i>=0,则说明
至少还有一个字符。
 */
    while((i>=0 )&&(s[i]==' '||s[i])=='\t')
    {
        i--;
    }

    if(i>0)                     //非全空格行
    {
        i++;                    //
        s[i]='\n';              //put newline character
        i++;
        s[i]='\0';
    }
    return i;
}
