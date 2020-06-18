#include<cstdio>
#include<memory>


void Print1ToMaxOfDigits_1(int n)
{
    if(n<=0)
        return;
    
    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while(!Increment(number))
    {
        PrintNumber(number);
    }
    delete []number;
}

bool Increment(char* number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);
    for(int i= nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if(i == nLength - 1)
            nSum++;
        if(nSum >= 10)
        {
            if(i==0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
        
    }

    return isOverflow;
}

void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i =0; i < nLength; ++i)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if(!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }
    printf("\t");
}
// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
