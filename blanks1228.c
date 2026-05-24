#include <stdio.h>
// replace blanks to blanks+minimum tabs;
void main()
{
    const unsigned int tab_inc = 8;
    unsigned int nb, nt = 0;  //nb = blanks num, nt = tab nums;
    for(unsigned int pos=1; (c=getchar())!=EOF; pos++)
    {
        if(c==' ')
        {
            if((pos%tab_inc)!=0)
            {
                nb++;
            }
            else
            {
                nt++;
                nb=0;
            }
        }
        else
        {
            //firstly, print tables and blanks;
            while(nt>0)
            {
                putchar('\t');
                nt--;
            }
            if(c=='\t')
            {
                nb=0;
            }
            else
            {
                while(nb>0)
                {
                    putchar(' ');
                    nb--;
                }
            }
            //secondly, print character;
            putchar(c);
            //thirdly, other branch
            if(c=='\n')
            {
                pos=0;
            }
            else if(c=='\t')
            {
                pos = pos+tab_inc-(pos-1)%tab_inc -1; // Ωÿ÷πŒª÷√
            }
        }
    }
}
