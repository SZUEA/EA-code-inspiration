#include <stdio.h>
int main()
{
    // e=1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
    double sum = 0;
    int acc = 0;
    for (int i = 1;; i++)
    {
        double unit = 1;
        for (int j = 1; j <= i; j++)
            unit /= j;
        sum += unit;
        if (unit < 1e-5)
        {
            acc = i;
            break;
        }
    }
    printf("Constant number e is:%lf\n", 1 + sum);
    printf("There are %d numbers added.", 1 + acc);
    return 0;
}