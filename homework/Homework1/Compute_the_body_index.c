#include <stdio.h>
#define cal(wt, ht) wt / (ht * ht)
int main()
{
    float weight, height;
    printf("Please input your weight(kg):");
    scanf("%f", &weight);
    printf("Please input your height(m):");
    scanf("%f", &height);
    printf("Your body index is:%f", cal(weight, height));
    return 0;
}