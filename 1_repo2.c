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
void get_file(FILE *fp,FILE *fi , int chr)
{
    int i = 0;
    while ((chr = fgetc(fp)) != EOF && i<10)
    {
        if(isalpha(chr) == 0)chr = ' ';
        fputc(chr , fi);
        putchar(chr);
        i++;
    }
}
char judge(char trans){

}
int main()
{
    FILE *fp , *fi;
    int chr;
    char read, write;
    char fname[] = "test.txt";
    char fna[] = "write.txt";
    fi = fopen(fna , "w");
    fp = fopen(fname, "r");
    read_file(fp);
    get_file(fp , fi , chr);
    fclose(fp);
}