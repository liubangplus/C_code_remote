#include <stdio.h>

/* this code shows relation ship between the Fahr and Celsius degrees
*/

int main()
{
    #define LOWER 0
    #define UPPER 300
    #define STEP 20

    int Fahr=0;
    printf("Fahr Celsius\n");
    for(Fahr = UPPER; Fahr >= LOWER; Fahr=Fahr - STEP)
    {
       printf("%3d %6.1f\n",Fahr, (5.0/9.0)* (Fahr-32.0));
    }



//
//    float Fahr,Celsius;
//    int lower, upper, step;

//    lower=0;   /*lower limit of temperature table*/
//    upper=300; /*upper limit of temperature table*/
//    step=20;   /*step of temperature table*/

//    Fahr=lower;   /*before calculation, "lower" will be transfered to float firstly */
//    printf("Fahr Celsius\n");
//    while(Fahr<=upper)
//    {
//        Celsius = (5.0/9.0)* (Fahr-32.0);
//        printf("%3.0f %6.1f\n", Fahr, Celsius);  /* %6f means width is 6, %.2f means number of decimal places is 2*/
//        Fahr=Fahr+step;
//
//
//    }

    //printf("hello, world\n");

//
return 0;
}
