#include <stdio.h>
int main()
{
    double score;
    printf("请输入成绩:");
    scanf("%lf", &score);
    if (score > 100 || score < 0)
        printf("数据输入错误！");
    else if (score >= 90)
        printf("你的等第是A");
    else if (score >= 80)
        printf("你的等第是B");
    else if (score >= 70)
        printf("你的等第是C");
    else if (score >= 60)
        printf("你的等第是D");
    else
        printf("你的等第是F");
    return 0;
}