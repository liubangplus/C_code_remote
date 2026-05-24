#include <stdio.h>
#include <string.h>
/*strrindex: returns rightmost index of t in s, -1 if none*/
/*int strrindex(char s[], char t[])
{
    int i, j, k, pos;
    pos = -1;
    for(i=0; s[i]!='\0';i++)
    {
        for(j=i, k=0; (t[k]!='\0')&&(s[j]==t[k]);j++,k++)
        {
            //
        }
        if((k>0)&&(t[k]=='\0'))
        {
            pos = i;
        }
    }
    return pos;
}*/

int strrindex(char s[], char t[])
{
    int i, j, k;

    int pos = -1;
    for(i=(strlen(s)-strlen(t)); i>=0;i--)
    {
        for(j=i, k=0; t[k]!='\0'&&s[j]==t[k];k++,j++)
        {

        }
        if(k>0&&t[k]=='\0')
        {
            pos=i;
        }
    }
    return pos;
}


void main()
{
    char *s= "abcde";
    char *t= "de";
    int i=0;
    i = strrindex(s,t);
    printf("right_most_index = %d \n", i);
}
