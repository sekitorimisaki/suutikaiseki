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
int deside_first_letter(FILE *read, FILE *write, int number_file)
{
    int letter_number = rand() % number_file;
    int chr, count = 0;
    srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化

    while ((chr = fgetc(read)) != EOF && count < letter_number)
    {
        count++;
    }
    fputc(chr, write);
    chr = fgetc(read);

    return chr;
}
int deside_next_letter(FILE *read, FILE *write, int number_file, int recently_letter)
{
    int letter_number = rand() % number_file + 1;
    int chr, count = 0, frag = 0, overflow = '\0';
    while ((chr = fgetc(read)) != EOF && count < letter_number)
    {
        if (overflow == '\0' && chr == recently_letter)
        {
            frag = 1;
        }
        if (frag == 1)
        {
            overflow = chr;
            frag = 0;
        }
        count++;
    }
    while ((chr = fgetc(read)) != EOF)
    {
        if (chr == recently_letter)
        {
            break;
            frag = 0;
        }
    }
    if (chr == recently_letter)
    {
        frag = 0;
    }
    if (frag == 0)
    {
        chr = fgetc(read);
        fputc(chr, write);
    }
    else if (frag == 1)
    {
        fputc(overflow, write);
        chr = fgetc(read);
    }
    count++;

    return chr;
}
int main()
{
    FILE *read, *write;
    int number_file, letter_number;
    int next_letter, recently_letter, write_letter[100];
    int result;
    char read_name[] = "1_result.txt";
    char write_name[] = "5_result.txt";
    srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
    read = fopen(read_name, "r");
    number_file = count_letter(read);
    fclose(read);
    read = fopen(read_name, "r");
    write = fopen(write_name, "w");
    next_letter = deside_first_letter(read, write, number_file);
    write_letter[0] = next_letter;
    fclose(read);
    for (int i = 1; i < 100; i++)
    {
        recently_letter = next_letter;
        read = fopen(read_name, "r");
        next_letter = deside_next_letter(read, write, number_file, recently_letter);
        write_letter[i] = next_letter;
        fclose(read);
    }
    fclose(write);
}