#include <string.h> 
 void findPalindrome(int ans[], char *str, int begin, int end, int stringlength)
 {
        while (str[begin] == str[end]) 
        {
            if (end - begin + 1 > ans[0]) { // 更新最大回文子串
                ans[0] = end - begin + 1;
                ans[1] = begin;
                ans[2] = end;
            }
            // 抵达边界则跳出循环
            if (begin == 0 || end == (stringlength) - 1) 
            {
                break;
            }
            // 向两边延展
            begin--;
            end++;
        }
}

char *longestPalindrome(char *s)
{
        int ans[] = {1, 0, 0};  // 用来记录最大回文字串长度，起始下标和终止下标
        char *result;
        int n=10000;
        result =(char *)malloc(sizeof(char)*n);
        int inputstringlength=strlen(s);

        for(int i = 0; i < (inputstringlength); i++) 
        {  // 遍历以所有字符为中心的情况
            // 子串为奇数的情况，从中心开始延展
            findPalindrome(ans, s, i, i, inputstringlength);
            // 子串为偶数的情况，从中间两个字符开始延展
            if (i + 1 < (inputstringlength) && s[i] == s[i + 1]) {
                if (ans[0] < 2) {
                    ans[0] = 2;
                    ans[1] = i;
                    ans[2] = i + 1;
                }
                findPalindrome(ans, s, i, i + 1, inputstringlength);
            }
        }
    //memcpy(result, &s[ans[1]], ans[0]);
    for(int m = 0;m < ans[0]; m++)
    {
        result[m]=s[ans[1]+m];
    }
    result[ans[0]]='\0';
    return result;
//    free(result);
}
