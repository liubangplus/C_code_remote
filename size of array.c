
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

int *sumArray;
int i=0;
int j=0;
int totalLength=nums1Size+nums2Size;
double averageNumber=0;

sumArray = (int *) malloc (sizeof(int)*(totalLength));
for(i=0;i<nums1Size;i++)
{
    sumArray[i]=nums1[i];
}
for(j=0;j<nums2Size;j++)
{
    sumArray[nums1Size+j]=nums2[j];
}

bubbleSort(sumArray,totalLength);  //冒泡法排序
averageNumber=(double)(sumArray[(totalLength-1)/2]+sumArray[(totalLength)/2]);
averageNumber=averageNumber/2;

return averageNumber;
}


 /*数组长度上限*/
 /*元素类型*/

/* 冒泡排序 */
/* 1. 从当前元素起，向后依次比较每一对相邻元素，若逆序则交换 */
/* 2. 对所有元素均重复以上步骤，直至最后一个元素 */
/* elemType arr[]: 排序目标数组; int len: 元素个数 */
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


