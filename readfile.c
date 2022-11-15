#include <stdio.h>
#include <ctype.h>
void read_file(FILE *fp )
{
    if (fp == NULL)
    {
        printf(" file not open!\n");
    }
    else
    {
        printf("file opened!\n");
    }
}
void get_file(FILE *fp, int chr)
{
    while ((chr = fgetc(fp)) != EOF)
    {
        putchar(chr);
    }
}
int main()
{
    FILE *fp;
    int chr;
    char read, write;
    char fname[] = "test.txt";
    fp = fopen(fname, "r");
    read_file(fp);
    get_file(fp, chr);
    fclose(fp);
}