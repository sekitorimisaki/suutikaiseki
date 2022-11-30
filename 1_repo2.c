// test.txtの中の英語だけを取り出して一文字ずつwriteファイルに書き込むプログラム
#include <stdio.h>
#include <ctype.h>
void read_file(FILE *fp)
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
void write_file(FILE *fp, FILE *fi, int chr)
{
    int i = 0;
    while ((chr = fgetc(fp)) != EOF)
    {
        if (chr != ' '&& chr != '\n')
        {
            if (isalpha(chr) == 0)
            {
                chr = ' ';
            }
        }
        fputc(chr, fi);
        putchar(chr);
        i++;
    }
}
int main()
{
    FILE *fp, *fi;
    int chr;
    char read, write;
    char fname[] = "original.txt";
    char fna[] = "1_result.txt";
    fi = fopen(fna, "w");
    fp = fopen(fname, "r");
    read_file(fp);
    write_file(fp, fi, chr);
    fclose(fp);
}