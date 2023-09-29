#include "stdio.h"
#include "math.h"
int main()
{
    int a;
    printf("请输入从某日午夜零点到现在已经经历的以秒为单位的时间:\n");
    scanf("%d",&a);
    printf("到现在为止已过了%d天\n",a/86400);
    printf("现在时间是%d时%d分%d秒",a%86400/3600,a%3600/60,a%60);
    return 0;
}
