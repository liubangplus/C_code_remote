#include <stdio.h>


void main()
{
    const unsigned int tab_inc = 8;
    char c = '\0';
    int pos = 1;
    int nb = 0;
    while((c=getchar())!=EOF)
    {
        if(c=='\t')
        {
            nb=tab_inc-(pos-1)%tab_inc;
            while(nb>0)
            {
                putchar(' ');
                pos++;
                nb--;
            }
        }
        else if(c=='\n')
        {
            putchar(c);
            pos=1;
        }
        else
        {
            putchar(c);
            pos++;
        }
    }
}
