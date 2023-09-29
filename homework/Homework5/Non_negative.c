#include <stdio.h>

int main()
{
    int arr[20], sum = 0, cnt = 0;
    //遍历二十个数
    printf("%s","请输入二十个整数:\n");
    for (int i = 0; i < 20; i++)
    {
        /*
            *p为第一个元素，第二个元素为*(p+1),以此类推...
            0 * ++cnt对符合条件的数计数器加一，不对sum变量影响
        */
        int *p = arr + i;
        scanf("%d", p);
        sum += *p >= 0 ? *p + 0 * ++cnt : 0;
    }
    printf("非负整数和为:%d\n非负整数个数为:%d", sum, cnt);
    return 0;
}