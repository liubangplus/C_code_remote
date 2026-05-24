/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXMIUMPIXEL 100

int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){

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