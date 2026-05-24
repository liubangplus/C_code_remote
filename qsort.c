#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
int cmpint(const void* p1, const void* p2 )
{
     return *(int*)p1- *(int*)p2;
}

/*int main()
{
    int array[]={1,3 , 5, 6 ,9,6,63};
    qsort(array, sizeof(array)/sizeof(array[0]), sizeof(int),cmpint);

    bool searchflag=false;
    for(int i=1; i< sizeof(array)/sizeof(array[0]); i++)
{
    if(array[i]==array[i-1])
    {
        searchflag=true;
        break;
    }


}
    printf("%d ", searchflag);
    return searchflag;
}*/
