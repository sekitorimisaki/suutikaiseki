#include <stdio.h>
#include <ctype.h>
void read_file(FILE *fp)
{
    char fname[] = "test.txt";
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
    char read, write;
    read_file(fp);
}