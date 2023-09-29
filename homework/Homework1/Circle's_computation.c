#include <stdio.h>
#define M_PI 3.14159265358979323846
#define girth(a) M_PI *a * 2.0
#define area(a) a *M_PI *a
int main()
{
    float radius;
    printf("Please input the radius of a circle:");
    scanf("%f", &radius);
    printf("The circle's perimeter is:%f\n", girth(radius));
    printf("The circle's area is:%f", area(radius));
    return 0;
}