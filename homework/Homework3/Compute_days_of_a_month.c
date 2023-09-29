#include <stdio.h>

int main()
{
    int year, month;
    int days[] = {31,28,30};
    printf("Please input the year and the month:");
    scanf("%d%d", &year, &month);
    if (year % 400 == 0 || (year % 4 == 0) && (year % 100 != 0))
    {
        days[1] = 29;
    }
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    printf("%d year %d month owns %d days.", year, month, days[0]);
        break;
    case 2:    
    printf("%d year %d month owns %d days.", year, month, days[1]);
        break;
    default:
    printf("%d year %d month owns %d days.", year, month, days[2]);
        break;
    }
}
