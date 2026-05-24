char * longestCommonPrefix(char ** strs, int strsSize)

// algo {fluence,float,fly};  use all characters of strs[0][], max common is itself,  
//if strs[0][counter]==strs[i][counter], search go on,counter++, or else search end;
{
int count = 0;

    while(strs[0][count]!='\0')
    {
       for(int i=0; i<strsSize; i++)
        { 
            if(strs[0][count]!=strs[i][count])
            {
                strs[0][count]='\0';
                return strs[0];
            }
        }
    count++;
    }

return strs[0];


}