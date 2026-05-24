#include <ctype.h>
#include <limits.h>

/*convert string s to a int */
int myAtoi(char* s) 
{
    long long val;
    int i, sign;
    for(i=0; isspace(s[i]); i++) //skip space;
    {;}
    
    sign = (s[i]=='-') ? (-1) : 1; //confirm sign;
    if((s[i]=='+')||(s[i]=='-'))
    {
        i++;
    }

    for(val= 0; isdigit(s[i]); i++)//digits
    {
        val=10*val + (s[i]-'0');

        if(val != (int)val)   // 简单判断是否被截断；
        {
             if(sign == 1) 
             {
                val= INT_MAX;  //2^31-1, 
             }
             else
             {
                val= INT_MIN; //-2^31
             }
             break;
            }
    }
    val = sign * val;

    return val;
}



