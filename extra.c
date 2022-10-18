#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int init(int value)
{
    printf("行数を入力してください");
    scanf("%d", &value);
    while (value < 2 || value > 10)
    {
        printf("もう一回入力してください");
        scanf("%d", &value);
    }
    return value;
}
double sum_hikizan(double *x, int gyouretu[][10] , int size, int number)
{
    double sum_value = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == number)
        {
            continue;
        }
        else
        {
            sum_value += gyouretu[number][i]*x[i];
        }
    }

    return sum_value;
}
double get_x(int *kotae, double *x, int gyouretu[][10], int number, int size)
{
    return ((kotae[number] - sum_hikizan(x, gyouretu ,size, number)) / gyouretu[number][number]);
}

bool judge(double pre_x[10], double x[10], int value)
{
    bool syuusoku = true;
    for (int i = 0; i < value; i++)
    {
        if (fabs(pre_x[i] - x[i]) < 0.0000000001)
        {
            syuusoku = true;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int i = 0, syuusoku = 0, round = 0;
    int value;
    int gyouretu[10][10], kotae[10];
    double x[10] = {1,1,1,1,1,1,1,1,1,1}, pre_x[10] = {1.0};

    value = init(value);

    for (i = 0; i < value; i++)
    {
        for (int j = 0; j < value; j++)
        {
            scanf("%d", &gyouretu[i][j]); //横i,縦j
        }
    }

    for (i = 0; i < value; i++)
    {
        printf("答えを入力してください");
        scanf("%d", &kotae[i]);
    } //入力終了
    while (1)
    {
        for (i = 0; i < value; i++)
        {
            pre_x[i] = x[i];
        }
        ///////////////////計算
        for (i = 0; i < value; i++)
        {
            x[i] = get_x(kotae, x, gyouretu, i, value);
        }

        //////////////////表示させる////////////
        printf("round %d : ", round + 1);
        for (int j = 0; j < value; j++)
        {
            printf("%12.10f ", x[j]);
        }
        printf("\n");
        if (judge(pre_x, x, value))
        {
            break;
        }
        round++;
    }
    return 0;
}
