#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15
#define MAXCHAR 128

void main()
{
    int c, i;
    int len;
    int maxvalue;
    int cc[MAXCHAR];

    for(int i=0; i<MAXCHAR;i++)
    {
        cc[i]=0; //initialize
    }
    while((c=getchar())!=EOF)
    {
        if(c<MAXCHAR)
        {
            cc[c]++;
        }
    }
    maxvalue=0;
    for(i=1; i< MAXCHAR; i++)
    {
        if(cc[i]>maxvalue)
        {
            maxvalue = cc[i];
        }
    }
    for(i=1;i<MAXCHAR;i++)
    {
        if(isprint(i))
        {
            printf("%5d - %c - %5d : ", i, i, cc[i]);//中间是int转成可打印ASCII值
        }
        else
        {
            printf("%5d -  - %5d : ", i, cc[i]);
        }
        if(cc[i]>0)
        {
            len = (cc[i]*MAXHIST)/maxvalue;
            if(len>=0){len=1;}
        }
        else
        {
            len=0;
        }
        while(len>0)
        {
            putchar('*');
            --len;
        }
        putchar('\n');
    }

}
