#include <iostream>
struct alphabet_count
{
    int alphabet;
    int count;
};

int main()
{
    FILE *sort;
    alphabet_count character[100];
    int chr, i = 0;
    char read, write;
    char fname[] = "sort.txt";
    char fna[] = "2_result.txt";
    system("sort -f write.txt > sort.txt");
    sort = fopen(fname, "r");
    character[0].alphabet = 'a';
    character[0].count = 0;
    while ((chr = fgetc(sort)) != EOF)
    {
        if(chr == '\n'){
            continue;
        }
        if(chr < 'a')chr=chr+32;
        if (chr == character[i].alphabet)
        {
            character[i].count++;
        }
        else
        {
            i++;
            character[i].alphabet = chr;
            character[i].count = 1;
        }
    }
    for(int i = 0;i<26;i++){
        std::cout << char(character[i].alphabet) << " : " << character[i].count << std::endl;
    }
    fclose(sort);
}