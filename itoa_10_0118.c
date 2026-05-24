#if 1
#define abs(x)  ((x) < 0 ? (-x) : (x))

/*itoa: convert n to character in s - modified*/
void itoa(int n, char s[], int w)
{
    int i, sign;
    void reverse(char s[]);

    sign = n;
    i=0;
    do
    {
        s[i++]=abs(n%10)+'0';
    }while((n=n/10)!=0);
    if(sign<0)
    {s[i++]='-';}
    while(i<w)
    {
        s[i++]=' ';
    }
    s[i]='\0';
    reverse(s);

}
#endif

/* itob: convert n to character in s - base Hex
void reverse(char s[]);
void itob(int n, char s[], const int b)
{
    int i, j, sign;

    if((sign=n)<0)
    {
        n=-n;
    }
    i=0;
    do
    {
        j= n % b;
        s[i++]=((j <=9) ? (j+'0' ) : (j+'0'-'a'));
    }while((n=n/b)>0);
    if(sign<0){s[i++]='-';}
    s[i]='\0';
    reverse(s);
}

void main()
{
    int n;
    char *s;
    const int b = 0xF;
    itob(n, s, b);
}*/









