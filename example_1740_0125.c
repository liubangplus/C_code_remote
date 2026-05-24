#if 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP   100 /* max size of operand or operator */
#define NUMBER  '0' /* signal that a number was found */
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
double atof_cal(char s[]);
void clear(void);

/*reverse Polish calculator*/
int main()
{
    int type;
    double op2, op1;
    char s[MAXOP];

    while((type=getop(s))!=EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s)); //string to double;
                break;
            case '+':
                push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            case '-':
                op2=pop();
                push(pop()-op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop()/op2);
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2=pop();
                if(op2!=0.0)
                {
                    push(fmod(pop(),op2));
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            case '?':
                op2=pop();
                printf("\t%.8g\n",op2);
                push(op2);
                break;
            case 'c':
                clear();
                break;
            case 'd':
                op2=pop();
                push(op2);
                push(op2);
                break;
            case 's':
                op1=pop();
                op2=pop();
                push(op1);
                push(op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}


int sp=0;
double val[MAXVAL];
/*push: push f onto value stack*/
void push(double f)
{
    if(sp<MAXVAL)
    {
        val[sp++]=f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}
/*pop: pop and return top value from stack*/
double pop(void)
{
    if(sp>0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}


/*getop: get next operator or numeric operand*/
int getop(char s[])
{
    int c, i;
    while((s[0]=(c=getch()))==' '||c == '\t')
    {
        ;
    }
    s[1]='\0';
    i=0;
    if((!isdigit(c))&&(c!='.')&&(c!='-'))
    {
        return c; //not a number;
    }
    if(c=='-')
    {
        if(isdigit(c=getch())||c=='.')
        {
            s[++i]=c;   /*negative number*/
        }
        else
        {
            if(c!=EOF){ungetch(c);}
            return '-';   /*minus sign*/
        }
    }

    if(isdigit(c))              /*collect integer part*/
    {
        while(isdigit(s[++i]=(c=getch())))
        {
            ;
        }
    }
    if (c=='.')                 /*collect fraction part*/
    {
        while(isdigit(s[++i]=(c=getch())))
        {
            ;
        }
    }
    s[i]='\0';
    if(c!=EOF){ungetch(c);}
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;

int getch(void)
{
    return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
    if(bufp>=BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
        buf[bufp++]=c;
}

double atof_cal(char s[])
{
    double val,power;
    int i, sign;

    for(i=0; isspace(s[i]);i++)
    {
        ;
    }
    sign=(s[i]=='-')?-1:1;
    if((s[i]=='+')||(s[i]=='-'))
    {
        i++;
    }
    for(val=0.0; isdigit(s[i]);i++)
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
    return sign*val/power;
}

/*clear: clear the stack*/
void clear(void)
{
    sp=0;
}
#endif
