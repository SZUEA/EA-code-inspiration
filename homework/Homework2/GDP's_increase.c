#include "stdio.h"
#include "math.h"
int main()
{
    printf("Ten years later, GDP has grown by %.0lf percent.",100*(pow(0.06+1,10)-1));
    return 0;
}
