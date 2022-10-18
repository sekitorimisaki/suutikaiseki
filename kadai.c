#include <stdbool.h>
#include <stdio.h>
#include <math.h>
double get_x1(double x2, double x3)
{
    return ((10. - x2 - x3) / 5.);
}
double get_x2(double x1, double x3)
{
    return ((12. - x1 - x3) / 4.);
}
double get_x3(double x1, double x2)
{
    return ((13. - 2. * x1 - x2) / 3.);
}
bool judge(double x1, double pre_x1 , double x2 , double pre_x2 , double x3 , double pre_x3)
{
    bool syuusoku = true;
    if (fabs(x1 - pre_x1) < 0.0000000001 && fabs(x2 - pre_x2) < 0.0000000001 && fabs(x3-pre_x3) <  0.0000000001)
    {
        syuusoku = true;
    }
    else
    {
        return false;
    }

    return true;
}
int main()
{
    double x1, x2, x3;
    double pre_x1 , pre_x2 , pre_x3;
    int i = 0;

    x1 = x2 = x3 = 1.0;
    printf("round: %2d (%12.10f, %12.10f, %12.10f)\n", 0, x1, x2, x3);
    while (1)
    {
        pre_x1 = x1;
        pre_x2 = x2;
        pre_x3 = x3;
        x1 = get_x1(x2, x3);
        x2 = get_x2(x1, x3);
        x3 = get_x3(x1, x2);
        if(judge(x1, pre_x1 , x2 , pre_x2 , x3 , pre_x3))break;
        printf("round: %2d (%12.10f, %12.10f, %12.10f)\n", i + 1, x1, x2, x3);
        i++;
    }
    return 0;
}
