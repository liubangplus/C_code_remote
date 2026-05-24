#include <ctype.h>
#include <stdio.h>
/*atof: convert string s to double*/
double atof_1(char s[])
{
    double val, power;
    int exp, i=0, sign;
    val=0;

    for(i=0; isspace(s[i]);i++)
    {
        ;
    }
    if(s[i]=='-'){sign=-1;}
    else{sign=1;}
    //if(s[i]=='+'||s[i]=='-')
    //{
    //    i++;
    //}
    for(val=0;isdigit(s[i]);i++)
    {
        val=(s[i]-'0')+val*10;
    }
    if(s[i]=='.')
    {
        i++;
    }
    for(power=1.0;isdigit(s[i]);i++)
    {
        val=(s[i]-'0')+val*10;
        power=power*10;
    }
    val=sign*val/power;

    if((s[i]=='e')||s[i]=='E')
    {
        if(s[++i]=='-'){sign=-1;i++;}
        else{sign=1;i++;}
        for(exp=0; isdigit(s[i]);i++)
        {
            exp=exp*10+s[i]-'0';
        }
        if(sign==1)
        {
            while((exp--)>0)
            {
                val=val*10;
            }
        }
        else
        {
            while((exp--)>0)
            {
                val=val/10;
            }
        }
    }
    return val;

}

void main_2()
{
    char *s = "123.45E-6";
    double value = atof_1(s);
    printf("string actual value = %lf\n", value);
}
