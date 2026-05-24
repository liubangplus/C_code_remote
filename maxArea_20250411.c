

int maxArea(int* height, int heightSize)
{
    int square=0;
    int left =0;
    int right=heightSize-1;

    //持续时用while查找，
    //矩形面积=高(使用fmin 得到高度较矮的一边)*底(直接right-left, 不是数点不需要加1)
    //square = fmax(square, (right-left)* fmin(height[left], height[right]))  // 使用了反复迭代，直至找到最大值； 

    while(left<right)
    {

        int min=fmin(height[left],height[right]); //找出可对应的两条边（由于会出现一边高，一边低的现象，因此需要就低原则）
        square=fmax(square,(right-left)*min);//求出最大面积;   

        if(height[left]>height[right]) //右边矮，以右边为主
        {   //让最短的一条边移动，减少花费
            right--; //右边向中心移动以寻求最大面积；
        }
        else //左边矮，以左边为主
        {
            left++; //左边向中心移动
        }
        //继续while 迭代最大面积循环；
    }
     return square;
}

