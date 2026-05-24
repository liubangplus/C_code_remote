int reverse(int x)
{
    int max = 0x7fffffff;
    long b = 0;
    while (x != 0)
    {
        b = b * 10 + x % 10;
        x = x / 10;
    }

    if(b > max || b < (-1 * (max + 1)))
    {
        return 0; //防止越界
    }
    else
    {
        return b;
    }

}