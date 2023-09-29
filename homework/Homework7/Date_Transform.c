#include <stdio.h>
#include <stdlib.h>
static int configDays[2][13] =
    {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
     {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

void showInfo()
{
    printf("在选单中选择:\n");
    printf("\t1.年,月,日变成在该年第几天\n");
    printf("\t2.在该年第几天变成年,月,日\n");
    printf("\t3.退出\n");
    printf("输入选项:");
}
void gtmthday(int y, int yd, int *mthp, int *dayp)
{
    int i, ly;
    ly = ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
    for (i = 1; yd > configDays[ly][i]; i++)
        yd = yd - configDays[ly][i];
    *mthp = i;
    *dayp = yd;
}
int gtyd(int y, int m, int d)
{
    int i, ly;
    ly = ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
    for (i = 1; i < m; i++)
        d = d + configDays[ly][i];
    return d;
}
int main()
{
    int y, m, d, yd, sel;
    while (1)
    {
        fflush(stdin);
        showInfo();
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            printf("请输入:年 月 日:\t");
            scanf("%d,%d,%d", &y, &m, &d);
            yd = gtyd(y, m, d);
            printf("该日期是这一年的第%d日\n", yd);
            break;
        case 2:
            printf("请输入:年 在该年第几天\t");
            scanf("%d %d", &y, &yd);
            gtmthday(y, yd, &m, &d);
            printf("该日期是%d月%d号\n", m, d);
            break;
        case 3:
            exit(0);
        default:
            printf("输入有误");
        }
    }
    return 0;
}
