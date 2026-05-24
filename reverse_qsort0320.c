#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 第0位  = 0 对字符串排序
          =1 对数字排序(-n)
第1位     =0 按升序排序
          =1 按降序排序
*/
#define NUMERIC 1
#define DECR 2
#define LINES 100

int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void qsort(char *v[], int left, int right, int(*comp)(void*, void*));
void writelines(char *lineptr[], int nlines, int decr);

static char option = 0;

/* swap: interchange v[i] and v[j]*/
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i]=v[j];
    v[j]=temp;
}

int strcmp(char *s, char*t)
{
    for(;*s==*t;s++,t++)
    {
        if(*s=='\0')
        {
            return 0;
        }
    }
    return (*s-*t);
}

int numcmp(char *s1, char *s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);

    if(v1<v2) return -1;
    if(v1>v2) return 1;
    return 0;

}

double atof(char s[])
{
    double val, power;
    int i, sign;

    for(i=0;isspace(s[i]);i++)
    {
        ;
    }
    sign=(s[i]=='-')?-1:1;
    if(s[i]=='+'||s[i]=='-')
    {
        i++;
    }
    for(val=0.0;isdigit(s[i]),i++)
    {
        val=10.0*val+(s[i]-'0');

    }
            if(s[i]=='.')
        {
            i++;
        }
    for(power=1.0;isdigit(s[i]);i++)
    {
        val=10.0*val+(s[i]-'0');
        power*=10.0;
    }
    return val*sign/power;
    strcat(out, " function returning");
}

/*qsort: sort v[left]...v[right] into increasing order*/
#if 0
void qsort(int v[], int left, int right)
{
    int i, last;
    //void swap(int v[], int i, int j); //只是声明；
    if(left>=right)/*do nothing if array contains*/
        {return;} /* fewer than two elements*/
    swap(v, left, (left+right)/2);/*move partitioon elem*/
    last=left;
    for(i=left+1;i<=right;i++)/*partition*/
    {
        if(v[i]<v[left])
        {
            swap(v,++last,i);
        }
    }
    swap(v, left, last); /* restore partition elem*/
    qsort(v, left, last-1);
    qsort(v, last+1, right);

}
#endif // 0

/*void main()
{
    int v[10]={9,8,7,6,5,4,3,2,1,0};
    qsort(v, 0, 9);
    for(int i=0; i<(sizeof(v)/sizeof(v[0]));i++)
    {
        printf("v[%d]=%d\n", i, v[i]);
    }
    printf("\n");
    return;
}*/

#if 0
/*sort input lines*/
int main(int argc, char *argv[])
{
    char *lineptr[LINES];
    int nlines;
    int c, rc=0;
    while((--argc>0)&&(*++argv)[0]=='-')
    {
        while(c=*++argv[0])
        {
            switch(c)
            {
            case 'n':
                option|=NUMERIC;
                break;
            case 'r':
                option|=DECR;
                break;
            default:
                printf("sort:illegal option %c\n", c);
                argc= 1;
                rc=-1;
                break;
            }
        }
    }
    if(argc)
    {
        printf("Usage: sort -nr \n");
    }
    else
    {
        if((nlines=readlines(lineptr, LINES))>0)
        {
            if(option&NUMERIC)
            {
                qsort((void **)lineptr,0,nlines-1,(int(*)(void*,void*))numcmp);
            }
            else
            {
                qsort((void **)lineptr,0,nlines-1,(int(*)(void*,void*))strcmp);
            }
            writelines(lineptr, nlines, option&DECR);
        }
        else
        {
            printf("input too big to sort \n");
            rc=-1;
        }
    }
    return rc;
}

/*writelines: write output lines*/
void writelines(char *lineptr[], int nlines, int decr)
{
    int i;
    if(decr)
    {
        for(i=nlines-1;i>=0;i--)
        {
            printf("%s\n",lineptr[i]);
        }
    }
    else
    {
        for(i=0;i<nlines;i++)
        {
            printf("%s\n",lineptr[i]);
        }
    }
}

#endif // 0
