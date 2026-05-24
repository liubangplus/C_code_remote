#include <stdbool.h>
bool isPalindrome(int x)
 {
        int max = 0x7fffffff;
        long b = 0;
        bool Palindrome = false;
        long incoming_int= x;
        while (x != 0)
        {
            b = b * 10 + x % 10;
            x = x / 10;
        }
    
        if(b > max || b < (-1 * (max + 1)))
        {
             return 0; //防止越界
        }
        else if (incoming_int<0)
        {
            Palindrome = false; // 负数天然不是回文数；
        }
        else if (b==incoming_int)
        {
            Palindrome = true;
        }
    
        return Palindrome;

}