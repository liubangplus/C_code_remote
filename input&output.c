
//print input to output, version 1
#include<stdio.h>
#include<string.h>
//count input characters;
//void main()
//{
//    long nc = 0;
//
//    while(getchar()!=EOF)
//    {
//        ++nc;
//
//    }
//    printf("%ld\n",nc);
//}
//count input lines;
//void main()
//{
//    char c;
//    int nline = 0;
//    int nspace = 0;
//    int ntabel = 0;
//    int nbackspace = 0;
//
//    //while((c=getchar())!=EOF)
//    {
//        c='\b';
//       printf("%c\n", c);
//    }
//
//}

/*replace tabs and backspaces with visible characters*/
//#define NONBlANK 'a'
void main()
{
    //char c, lastc;
    int c;
    typedef enum {OUT, IN}STATE_;
    STATE_ state = OUT;

    int clines = 0;
    int spaces =0;
    int cword = 0;
    char character = 0;

    while((c = getchar()) != EOF)
    {
        if((c == '\n')||(c == ' ')||(c == '\t'))
        {
            if(state == IN)
            {
                //putchar('\n');
                state = OUT;
            }
            if(c=='\n')
            {
                clines++;
                character++;
            } // count lines
            else if(c==' ')
            {
                spaces++;
                character++;
            }// count spaces
            else{character++;}
        }
        else
        {
            if(state == OUT)
            {
                state = IN;
                //putchar(c);
                cword++;
                character++;
            }
            else
            {
                //putchar(c);
                character++;
            }
        }
    }
    printf("%d lines, %d words, %d characters\n", clines, cword, character);
}







