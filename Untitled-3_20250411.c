#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void bubbleSort (int arr[], int len)
 {
    int temp;
    int i, j;
    for (i=0; i<len-1; i++) /* 外循环为排序趟数，len个数进行len-1趟 */
        {
          for (j=0; j<len-1-i; j++)
            { /* 内循环为每趟比较的次数，第i趟比较len-i次 */
            if (arr[j] > arr[j+1])
            { /* 相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        }
}

int maxArea(int* height, int heightSize) 
{
    int* height_transfer;
    height_transfer= (int*) malloc(sizeof(int)*heightSize);
    
    int width_position1; int width_position2;
    //int width_begin, width_end, width_mediun;
    int MAX_value=0;
    int SECOND_value=0;
    int MATCH_value=0;


    for(int i=0; i<heightSize; i++)
    {
        height_transfer[i]=height[i];
    } 

    for(int i=0; i< heightSize; i++) //max volunme water have to get a max height;
    {
        if(height[i] > MAX_value)
        {
            MAX_value= height[i];
            width_position1=i;
        }
    }
    printf("width_position1=%d, MAX_value=%d\n",width_position1, MAX_value);

    bubbleSort(height, heightSize);

    SECOND_value=height[heightSize-2]; //get 2nd last value; height pointer has changed after qsort func;

    for(int j=0; j<heightSize;j++) // get 2nd last value's width index;
    {
        if(height_transfer[j]==SECOND_value)
        {
            width_position2 = j;
            break;
        }
    }

    printf("width_position2=%d, SECOND_value=%d\n",width_position2, SECOND_value);

    return (SECOND_value)*(fabs(width_position2- width_position1));
   

}