#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

bool arePermutation(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();

    if (n1 != n2)
        return false;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for(int i=0; i < n1; i++)
    {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

bool arePermutation(string str1, string str2)
{
    if(str1.length() != str2.length())
        return false;
    int count[256] = {0};
    for(int i=0; i < str1.length(); i++)
    {
        int val = str1[i];
        count[val]++;
    }
    for(int i=0; i<str2.length(); i++)
    {
        int val = str2[i];
        count[val]--;
        if(count[val] < 0)
            return false;
    }
    return true;
}