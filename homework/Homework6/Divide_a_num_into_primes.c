/**
6. 从键盘任意输入一个正整数，若是素数，打印“没有因子，
是素数”的提示信息；若不是素数，
则由小到大打印其所有的素数因子，
如输入 120，输出应该是 120 = 2*2*2*3*5，或者
90=2*3*3*5
*/
#include <stdio.h>
#include <math.h>
void divide(int num)
{
    int flag = 1, rt = sqrt(num);
    for (int i = 2; i <= rt; i++)
        while (!(num % i))
        {
            if (flag)
                printf("%d is not a prime number, and its factorization is:\n%d = ",num, num + --flag);
            if (num / i == 1)
            {
                printf("%d", i);
                return;
            }
            printf("%d*", i);
            num /= i;
        }
    if (flag)
        printf( "%d is a prime number, and it has no factorization.",num);
    else
        printf("%d", num);
}
int main()
{
    int a;
    printf("Please enter a positive integer(n>=2):n=? ");
    scanf("%d", &a);
    divide(a);
    return 0;
}