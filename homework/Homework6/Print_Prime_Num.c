/**
 * 5. 编写一个函数，功能为判断一个整数是否为素数。
 * 在 main()函数中调用此自定义函数将
    100~200 之间的素数输出
*/
#include <stdio.h>
#include <math.h>
int isPrimeNum(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
        if (!(num % i))
            return 0;
    return 1;
}
int main()
{
    printf("100~200的素数为:\n");
    for (int i = 100; i <= 200; i++)
        if (isPrimeNum(i))
            printf("%d ", i);
    return 0;
}
