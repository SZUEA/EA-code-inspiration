#include <stdio.h>
int main()
{
    int a, b, c; // Three edges
    printf("Please input the three edges\n");
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    printf("c=");
    scanf("%d", &c);
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("The triangle can't be formed.");
    }
    else
    {
        double flag = (a * a + b * b - c * c) * (a * a + c * c - b * b) * (b * b + c * c - a * a);
        if (flag > 0)
            printf("The triangle is an acute one.");
        else if (flag == 0)
            printf("The triangle is a right-angled one.");
        else
            printf("The triangle is an obtuse one");
    }

    return 0;
}