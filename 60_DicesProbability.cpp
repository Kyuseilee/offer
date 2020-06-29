#include<cstdio>
#include<math.h>

int g_maxValue = 6;

void Probability(int number, int* pProbailities);
void Probability(int original, int current, int sum, int* nProbailities);

void PrintProbaility_Solution1(int number)
{
    if(number < 1)
        return ;
    
    int maxSum = number * g_maxValue;
    int* pProbailities = new int[maxSum - number + 1];
    for(int i = number; i <= maxSum; ++i)
        pProbailities[i - number] = 0;
    
    Probability(number, pProbailities);
    int total = pow((double)g_maxValue, number);
    for(int i = number; i <= maxSum; i++)
    {
        double ratio = (double)pProbailities[i - number] / total;
        printf("%d: %e\n", i, ratio);
    }
    delete[] pProbailities;
}

void Probability(int number, int* pProbabilities)
{
    for(int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, pProbabilities);
}

void Probability(int original, int current, int sum, int* pProbabilities)
{
    if(current == 1)
    {
        pProbabilities[sum - original]++;
    }
    else
    {
        for(int i = 1; i <= g_maxValue; ++i)
        {
            Probability(original, current - 1, i + sum, pProbabilities);
        }
    }
    
}


// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
    
    printf("Test for solution1\n");
    PrintProbability_Solution1(n);

    printf("Test for solution2\n");
    PrintProbability_Solution2(n);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);

    return 0;
}