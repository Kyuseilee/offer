#include<cstdio>

int NumberOf2_Solution(int n)
{
    int flag;
    if(n<=0)
        return false;
    
    if (!(n&(n-1)))
        {flag = 1;
        printf("Yes, it is.\n");
        }
    else
    {
        flag = 0;
    }
    
    return flag;
}

int main(int argc, char* argv[]){
    int a;
    a = NumberOf2_Solution(4);
    printf("%d", a);
    return 0;
}