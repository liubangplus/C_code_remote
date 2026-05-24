class Solution {
    public int largestPalindrome(int n) 
    {
        int ans = 0;
        if (n == 1) return 9;
        long max = (long)(Math.pow(10, n) - 1);
        boolean flag = false;
        for (long i = max - 2; i > 0; i--)
        {
            long palindr = i;
            // 从大往小构建回文数
            for (long x = palindr; x > 0; x /= 10)
            {
                palindr = palindr * 10 + x % 10;
            }
            // palindr构建完成
            // 从大往小尝试判断乘数,
            // 乘数的平方要大于palindr
            // 因为如果存在乘数的平方小于palindr并且其可以整除palindr，则一定已经检测过另一个大于它的乘数，矛盾！
            for (long multiplier = max; multiplier * multiplier >= palindr; multiplier--)
            {
                if (palindr % multiplier == 0)
                {
                    ans = (int)(palindr % 1337);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        return ans;
    }
}
