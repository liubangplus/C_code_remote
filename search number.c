int searchInsert(int* nums, int numsSize, int target){



int index_middle;
int return_index;
int index_left=0;
int index_right=numsSize-1;
int flag=0;
int index=0;

//如果target与nums[]中某一元素相同，则输出对应的index；
for(index=0;index<numsSize;index++)
{
    if(nums[index]==target)
    {
        flag=1;
        return index;
        break;
    }

}
//如果target小于nums[]中第0个最小元素或者大于第numsSize个最大元素，或者介于某两个元素之间
if(target<nums[0])
{
    flag=0;
    return 0;
}
else if(target>nums[numsSize-1])
{
    flag=0;
    return numsSize-1;
}
else
{
    while(index_left<=index_right)
{
index_middle=(index_right-index_left)/2+index_left;// 避免int+int 超出整型范围，利用中点计算；

if(nums[index_middle]>target&&nums[index_middle-1]<target)    //布尔运算判定
{

    flag=0;
    return index_middle;
    break;
}
else if(nums[index_middle]<target)
{
    index_left=index_middle+1;
      // 避免死循环，必须缩减范围，右边界左拓；
}
else if(nums[index_middle-1]>target)
{
    index_right=index_middle-1;// 避免死循环，必须缩减范围，左边界右拓
}
else
{
    //do nothing
}
}
}

//如果找到相同的数字与target相同，则直接输出；


//如果没有找到与target相同的数字，则进行比较后插入；


}
