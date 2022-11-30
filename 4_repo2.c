#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
int count_letter(FILE *fp)
{
    int chr, count = 0;
    while ((chr = fgetc(fp)) != EOF)
    {
        count++;
    }
    return count;
}
int write_letter(int number, FILE *read, FILE *write)
{
    int chr, count = 0, letter , result = 0;
    while ((chr = fgetc(read)) != EOF && count < number)
    {
        count++;
    }
    if(chr == '\n')return result;
    fputc(chr, write);
    result = 1;
    return result;
}
int main()
{
    FILE *read, *write;
    int number_file, letter_number;
    int chr;
    int result;
    char read_name[] = "write.txt";
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
        result = write_letter(letter_number, read, write);
        if(result == 0)i--;
        fclose(read);
    }
    fclose(write);
}