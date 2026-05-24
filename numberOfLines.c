#if 0
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXMIUMPIXEL 100

int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize)
{

int * answer = (int *) malloc( sizeof(int) * 2 );
int pixelsum = 0;
int alphabeta = 0;
int linecounter = 1;
int length = strlen(s);

for(int index = 0; index < length; index++)
{
    alphabeta = s[index] - 'a';
    pixelsum = pixelsum + widths[alphabeta];
    if(pixelsum > MAXMIUMPIXEL)
    {
        linecounter++;
        pixelsum = widths[alphabeta];
    }

}
*returnSize = 2;
answer[0] = linecounter;
answer[1] = pixelsum;

return answer;

}

#endif

int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize)
{

    int * answer = (int *) malloc( sizeof(int) * 2 );
    int pixelsum=0;
    int pixellastline=0;
    int charactersum= strlen(s);
    int pixellastline_character=0;
    int linecounter=0; 

    for(int i=0; i<charactersum;i++)
    {
        pixelsum = pixelsum + (widths[s[i] - 'a']);
        if(pixelsum > 100)
        {
            linecounter++;
            pixelsum = widths[s[i] - 'a'];
        }

    }

    linecounter= linecounter + 1; //从0计数；
    pixellastline= pixelsum; //最后一行进位宽度；

    *returnSize=2;
    answer[0] = linecounter;
    answer[1] = pixellastline;

    return answer;


}