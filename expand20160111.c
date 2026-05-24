/*expand: expand shorthand notation in s1 to string s2*/
#include <stdio.h>

/*void expand(char s1[], char s2[])
{
    char position[100][30];
    int k=0;
    int m=0;
    int count=0;
    for(int i=0; s1[i]!='\0'; i++)
    {
        if(s1[i]=='-')
        {
            if((i-1)<0){printf("error branch\n");}
            else
            {
                for(char a=s1[i-1]; a<=s1[i+1];a++)
                {
                    position[count][k]=a;
                    k++;
                }
            }
            position[count][k]='\0';
            count++;
            k=0;
        }
    }
    for(int i=0; i<count;i++)
    {
        for(int j=0; position[i][j]!='\0';j++)
        {
            s2[m]=position[i][j];
            m++;
        }
    }
    for(int i=0; i<m;i++)
    {
        printf("%c", s2[i]);
    }
}
*/

void expand(char s1[], char s2[])
{
    char c;
    int i, j;
    i = j = 0;
    while((c=s1[i++])!='\0')        //s[i-1]
    {
        if((s1[i]=='-')&&(s1[i+1]>=c)) //s[i]
        {
            i++;
            while(c<s1[i])            //s[i+1]
            {
                s2[j++]=c++;
            }
        }
        else
        {
            s2[j++]=c;
        }
    }
    s2[j]='\0';
    for(int x=0;x<j;x++)
    {
        printf("%c", s2[x]);
    }

}

void main()
{
    char s1[1000], s2[1000];

    s1[0]='A';
    s1[1]='-';
    s1[2]='B';
    s1[3]='B';
    s1[4]='-';
    s1[5]='C';
    expand(s1, s2);

}
