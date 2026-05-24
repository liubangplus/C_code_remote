#include <stdio.h>

float celsuis(float fahr);
/*
for fahr =0, 20, ..., 300; floating-point version
*/
void main()
{
    float fahr;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while((fahr<=upper)&&(fahr>=lower))
    {
        printf("%3.0f %6.1f\n", fahr, celsuis(fahr));
        fahr = fahr + step;
    }
}

float celsuis(float a)
{
    return (5.0*(a - 32.0)/9.0);
}
