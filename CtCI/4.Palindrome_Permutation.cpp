#include<iostream>

int getCharIndex(char c)
{
    int idx = -1;
    if(c >= 'a' && c <= 'z')
        idx = c - 'a';
    
    else if (c >= 'A' && c <= 'Z')
        idx = c - 'A';
    return idx;
}

void countFrequency(const std::string & str, int *frequency)
{
    int idx;
    for(const char& c: str)
    {
        idx = getCharIndex(c);
        if (idx != -1)
            ++frequency[idx];
    }
}

bool isPermutationOfPallindrome1(const std:: string& str)
{
    int frequency[26] = {0};
    countFrequency(str, frequency);
    
    bool oddAppeared = false;
    std::cout << std::endl;
    for(int i=0; i < 26; i++)
    {
        if(frequency[i]%2 && oddAppeared)
            return false;
        else if (frequency[i]%2 && !oddAppeared)
            oddAppeared = true;
    }
    return true;
}