/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <math.h>
#include <stdio.h>

int* addToArrayForm(int* num, int numSize, int k, int* returnSize){

int *answer=(int *)malloc(sizeof(int)*100000);
memset(answer,0,100000);

unsigned int intergernum1 =0; 
unsigned int intergernum2 =0; 
//int intergernum3 = 0;
int outputlength = 0;

//caculation 1, transfer array to integer;
for(int index = numSize-1; index >=0; index-- )
{
    intergernum1 = intergernum1 + num[index] * (unsigned int)(pow(10, numSize-1-index)) ;
}
printf("intergernum1=%d\n", intergernum1);

//caculation 2;
intergernum2 = intergernum1 + k;

//caculation 3, tranfer integer to array;
//intergernum3 = intergernum2;
for(int i = 0; i<=100000 ;i++)
{
    if(intergernum2 == (unsigned int)(pow(10,i)))
    {
        outputlength = i +1 ;
        break;
    }
    if ((intergernum2 /(unsigned int)(pow(10,i)))==0)
    {
        outputlength = i;
        break;
    } 
}

//outputlength = numlen (intergernum2);

for( int j = 0;j< outputlength;j++)
{  
    answer[outputlength-1-j] = (intergernum2 /(int)pow(10,j))%10;
}

*returnSize = outputlength;
return answer;


}