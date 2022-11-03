#include <stdio.h>
#include <ctype.h>
void read_file(FILE *fp , char fname[])
{
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("%s file not open!\n", fname);
    }
    else
    {
        printf("%s file opened!\n", fname);
    }
}
int main()
{
    FILE *fp;
    char fname[] = "test.txt";
    read_file(fp, fname);
}