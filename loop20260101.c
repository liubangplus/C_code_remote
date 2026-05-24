#include <stdbool.h>
#include <stdio.h>

/* htoi: convert hexadecimal string s to integer */
int htoi(char s[])
{
    int hexdigit, i, inhex, n;
    i=0;
    if(s[i]==0)
    {
        i++;
        if(s[i]=='x'||s[i]=='X')
        {
            i++;
        }
    }
    n=0;
    inhex = true;
    for(;inhex==true;i++)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            hexdigit = s[i] - '0';
        }
        else if((s[i]>='a')&&(s[i]<='f'))
        {
            hexdigit = s[i]- 'a' + 10;
        }
        else if((s[i]>='A')&&(s[i]<='F'))
        {
            hexdigit = s[i] - 'A' +10;
        }
        else
        {
            inhex = false;
        }
        if(inhex==true)
        {
            n=16*n+hexdigit;
                   printf(" s[%d]value = %x\n", i,n);

        }
    }

}

void squeeze(char s1[], char s2[])
{
    int i,j;
    int k=0;
    for(i=0;s1[i]!='\0';i++)
    {
        for(j=0;(s2[j]!='\0')&&(s1[i]!=s2[j]);j++)
        {
            ;
        }
        if(s2[j]=='\0')
        {
            s1[k]=s1[i];
            k++;
        }
    }
    s1[k]='\0';
}

int binsearch(char x, char v[], int n);

void array_print();

void main()
{
   //char s[]="AAAAA";
   // char s[]={'a', 'b', 'c', 'd', 'e', 'f'};
   // int m = binsearch('d', s, sizeof(s)/sizeof(s[0]));
   // htoi(s);
   //unsigned int A = 0;
   //printf("binsearch result= %d\n", m);

}

int binsearch(char x, char v[], int n)
{
    int low, high, mid;
    low=0;
    high = n-1;
    mid=(high+low)/2;
    while(low<=high)
    {
        if(x<v[mid]){high=mid-1;}
        else{low=mid+1;}
        mid = (high+low)/2;
    }
    if(x==v[mid]){return mid;}
    else {return -1;}
}

