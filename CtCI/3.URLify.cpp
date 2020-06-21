#include<iostream>
#include<cstring>

void urlify(char * str, int len)
{
    int numOfSpace = 0;
    int i = 0, j = 0;
    for(i = 0; i < len; ++i)
        if(str[i] == ' ')
            ++numOfSpace;   
    
    int extendedLen = len + 2 * numOfSpace;
    i = extendedLen - 1;
    for(j = len - 1; j >= 0; --j)
    {
        if (str[j] != ' ')
            str[i--] = str[j];
        else
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
        
    }
}