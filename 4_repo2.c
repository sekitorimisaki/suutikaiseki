#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
int count_letter(FILE *fp)//文字数のカウント
{
    int chr, count = 0;
    while ((chr = fgetc(fp)) != EOF)
    {
        count++;
    }
    return count;
}
void write_letter(int number, FILE *read, FILE *write)
{
    int chr, count = 0, letter , result = 0;
    while ((chr = fgetc(read)) != EOF && count < number)//適当に出した数字までの文字
    {
        count++;
    }
    fputc(chr, write);
}
int main()
{
    FILE *read, *write;
    int number_file, letter_number;
    int chr;
    int result;
    char read_name[] = "1_result.txt";
    char write_name[] = "4_result.txt";
    srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
    write = fopen(write_name, "w");
    read = fopen(read_name, "r");
    number_file = count_letter(read);
    fclose(read);
    for (int i; i < 100; i++)
    {
        read = fopen(read_name, "r");
        letter_number = rand() % number_file;
        write_letter(letter_number, read, write);
        fclose(read);
    }
    fclose(write);
}