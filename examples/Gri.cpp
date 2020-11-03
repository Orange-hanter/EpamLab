#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <cmath>

#define n  256
#define file_old Table::fileName 

typedef struct Table
{
    static int num_simble;
    static char fileName[20];

    int sibl = 0;
    int col = 0;
    
    void init(int i)
    {
        sibl = i;
        col = 0;
    }
};


double entropy(Table (&table)[n]){
    double en = 0;
    for(int i = 0; i < n; ++i){
        double p_ch = (double)table[i].col;
        en += p_ch * log2(p_ch);
    }
    return -1 * en;
}


void fileAnalysys(FILE* file, Table (&table)[n]){
 if (file != NULL)
        while (!feof(file))
        {
            int number = (int)fgetc(file) - 1;
            table[number].col++;
            Table::num_simble++;
        }
    fclose(file);
}


void printReport(FILE* file, Table (&table)[n]){
    fprintf(file, "%s\n", Table::fileName);
    fprintf(file, "%d\n\n", Table::num_simble);
    for (int i = 0; i < n; i++)
    {
        if (table[i].col > 0)
        {
            fprintf(file, "%d\t%d\n", table[i].sibl, table[i].col);
        }
    }
    //TODO ТУТ КУДАТО НАДО ВСТАВИТЬ РЕЗУЛЬТАТ ВЫЧИСЛЕНИЯ ФОРМУЛЫ entropy
    fprintf(file, "\n");
    fclose(file);
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    FILE *file = NULL;

    Table table[n];
    Table::fileName[19] = {'\0'};
    Table::num_simble = -1;

    for (int i = 0; i < n; i++)
        table[i].init(i);

    printf("Ведите название файла: ");
    scanf("%s", &file_old);
        
    fileAnalysys( fopen(file_old, "rb") , table);
   
    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
        {
            if (table[i].col <= table[k].col)
            {
                int men;
                men = table[k].col;
                table[k].col = table[i].col;
                table[i].col = men;
                men = table[k].sibl;
                table[k].sibl = table[i].sibl;
                table[i].sibl = men;
            }
        }

    char file_new[20] = {'\0'};
    for (int i = 0, k = 0; file_old[i] != NULL; i++)
    {
        if (file_old[i] == '.')
        {
            while (file_old[++i] != NULL)
                file_new[k++] = file_old[i];
            file_new[k++] = '0';
            file_new[k++] = '8';
            file_new[k++] = '.';
            file_new[k++] = 't';
            file_new[k++] = 'a';
            file_new[k++] = 'b';
        }
    }
    
    printReport( fopen(file_new, "w+") , table);
    file = NULL;
}