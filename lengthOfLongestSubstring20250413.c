int lengthOfLongestSubstring(char* s) 
{
    int a=0, max=0;
    int i, j;
    int start = 0;
    for(i=0; i<strlen(s); i++)
    {
        for(j=start;j<i; j++)
        {
            if(s[i]!=s[j])
            {
                a++; //无重复元素计数
            }
            else //有重复元素
            {
                start=j+1; //改变二层循环起始
                break;
            }
        }

        a=i-start+1;   // 如果全为无重复数， 与a++相等;   如果为二层循环break, 则为重新起始后的无重复字符串长度； 
        if(a>max)
        {
            max=a; //max记录a最大值
        }
    }   


    return max;
}