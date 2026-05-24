#include <stdio.h>

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];

int exptab(int pos, char line[]);   //expand tables
int findblank(int pos, char line[]); //find blank's position
int newpos(int pos, char line[]);  //rearrange line with new position
int printl(int pos, char line[]); //print line until position column 正常输出字符再换行

void main()
{
    char c;
    int pos = 0;
    while((c=getchar())!=EOF)
    {
        line[pos]=c;   //store
        if (c=='\n')
        {
            printl(pos, line);
            pos = 0;
        }
       // else if(c=='\t')
       // {
       //     pos = exptab(pos, line); // expand position when encounter a '\t';
      //  }
        else if(pos>= MAXCOL)
        {
            pos = findblank(pos, line);
            printl(pos, line);
            pos = newpos(pos, line);
        }
        ++pos;
    }
}

int printl(int pos, char line[])
{
    for(int i=0; i<pos;i++)
    {
        putchar(line[i]);
    }
    putchar('\n');
    return 0;
}

int exptab(int pos, char line[])
{
    line[pos]= ' ';
    pos++;
    while((pos<MAXCOL )&&(pos%TABINC!=0))
    {
        line[pos]=' ';
        pos++;
    }
    if(pos<MAXCOL)
    {
        return pos;
    }
    else
    {
        printl(pos, line);
        return 0;
    }
}

int findblank(int pos, char line[])
{
    while((pos>0)&&(line[pos]!=' '))
    {
        pos--;
    }
    if(pos==0)
    {
        return MAXCOL;
    }
    else
    {
        return pos+1;  // base on result;
    }
}

int newpos(int pos, char line[])
{
    int i, j;
    if((pos<=0)||(pos>MAXCOL))
    {
        return 0;
    }
    else
    {
        i=0;
        for(j=pos;j<MAXCOL;j++)
        {
            line[i]=line[j];
            i++;
        }
        return i;
    }
}

