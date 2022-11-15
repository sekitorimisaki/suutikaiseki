#include <stdio.h>
#include <ctype.h>
void write_file(FILE *fp)
{
    char fname[] = "write.txt";
    fp = fopen(fname, "w");
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
    fclose(fp);
}