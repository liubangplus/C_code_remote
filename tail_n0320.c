#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10
#define LINES 100
#define MAXLEN 100

void error(char *);
int getline(char *, int);

/* getline: get line into s, return length */
int getline(char s[],int lim)
{
    int c,i;
    i=0;
    while(--lim>0&&(c =getchar())!= EOF && c !='\n')
    {   s[i++]= c;
    }
        if(c =='\n');
        {
            s[i]='\0';
        }
        //printf("i=%d\n",i);
        //printf("s=%s\n", s);
    return i;
}
//int main(int argc, char *argv[])
int main_1()
{
    #if 1
    int argc =2;
    char *argv[] = {"-12",NULL};

    char *p;
    char *buf;
    char *bufend;
    char line[MAXLEN];
    char *lineptr[LINES];

    int first, i, last, len, n, nlines;
    if(argc==1)
    {
        n=DEFLINES;
    }
    else if((argc==2)&&(*(argv[0])=='-'))
    {
        n=atoi(argv[0]+1);
    }
    else
    {
        error("usage: tail[-n]");
    }
    if(n<1||n>LINES)
    {
        n=LINES;
    }
    for(i=0;i<LINES;i++)
    {
        lineptr[i]=NULL;
    }
    if((p=buf=malloc(LINES*MAXLEN))==NULL)
    {
        error("tail: cannot allocate buf");
    }
    bufend=buf+LINES*MAXLEN;
    last=0;
    nlines=0;
    while((len=getline(line, MAXLEN))>0)
    {
        if(p+len+1>=bufend)
        {
            p=buf;                  /*buffer wrap around*/
        }
        lineptr[last]=p;
        strcpy(lineptr[last],line);
        if(++last>=LINES)
        {
            last = 0;               /*ptrs to buffer wrap around*/
        }
        p+=len+1;
        nlines++;
    }
    if(n>nlines)                    /*req. lines more than rec.*/
    {
        n=nlines;
    }
    first= last -n;
    if(first<0)                     /*it did wrap around the list*/
    {
        first+=LINES;
    }
    for(i=first;n-->0;i=(i+1)%LINES)
    {
        printf("%s", lineptr[i]);
    }

    #endif
    char *s;
    int lim = 100;
    getline(s, lim);
    return 0;
}

/*error: print error message and exit*/
void error(char *s)
{
    printf("%s\n",s);
    exit(1);
}
