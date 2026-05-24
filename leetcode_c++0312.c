
int strcmp(char *s, char *t)
{
    int i;
    for(i=0; s[i]==t[i];i++)
    {
        if(s[i]]=='\0')
        {
            return 0;
        }
    }
    return s[i]-t[i];
}

int strcmp(char *s, char *t)
{
    for(;*s==*t;s++;t++)
    {
        if(*s=='\0'){return 0;}
    }
    return *s-*t;
}

#include <stdlib.h>
int max(int a, int b) { return (a > b) ? a : b; }


int findMaximumXOR(int* nums, int numsSize) {

    // int maxOp = 0;
    int temp = 0;
    int pop_len = numsSize;

    long long int maxOp = 0;

    if (pop_len == 1) {
    } else {
        while (pop_len > 0) {
            for (int i = 0; i < pop_len - 1; i++) {
                temp = 0;
                if (nums[i] > nums[i + 1]) {
                    temp = nums[i + 1];
                    nums[i + 1] = nums[i];
                    nums[i] = temp;
                }
            }
            pop_len--;
        }


        //for(int i=0; i<numsSize; i++)
        //{
        //    printf("nums[%d]=%d ", i, nums[i]);
        //}
        //printf("\n");

        for (int i = numsSize-1; i >=1; i--) {
            for (int j = i-1; j >= 0; j--) {
                // printf("nums[%d]=0x%X, nums[%d]=0x%X\n", i, nums[i],j, nums[j]);
                if (nums[j] < maxOp - nums[i]) {
                    break;
                }
                maxOp = max(maxOp, (long long)(nums[i] ^ nums[j]));
                // printf("maxOp=0x%x\n", maxOp);
            }
        }
    }
    return maxOp;
}


class Solution {
private:
    // 最高位的二进制位编号为 30
    static const int HIGH_BIT = 30;

public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            unordered_set<int> seen;
            // 将所有的 pre^k(a_j) 放入哈希表中
            for (int num: nums) {
                // 如果只想保留从最高位开始到第 k 个二进制位为止的部分
                // 只需将其右移 k 位
                seen.insert(num >> k);
            }

            // 目前 x 包含从最高位开始到第 k+1 个二进制位为止的部分
            // 我们将 x 的第 k 个二进制位置为 1，即为 x = x*2+1
            int x_next = x * 2 + 1;
            bool found = false;

            // 枚举 i
            for (int num: nums) {
                if (seen.count(x_next ^ (num >> k))) {
                    found = true;
                    break;
                }
            }

            if (found) {
                x = x_next;
            }
            else {
                // 如果没有找到满足等式的 a_i 和 a_j，那么 x 的第 k 个二进制位只能为 0
                // 即为 x = x*2
                x = x_next - 1;
            }
        }
        return x;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/solutions/778291/shu-zu-zhong-liang-ge-shu-de-zui-da-yi-h-n9m9/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


