char * longestCommonPrefix(char ** strs, int strsSize)
{
    int cnt=0;
    while(strs[0][cnt] != '\0')
    {
        for(int i=0; i<strsSize; i++)
        {
            if(strs[0][cnt] != strs[i][cnt]) 
            {
                strs[0][cnt] = '\0'; 
                return strs[0];   
            }
        }
        cnt++;  
    }
    return strs[0]; 
}
