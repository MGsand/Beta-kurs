#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
void format(int ds);
void noformat(int ds);
void paragraph();
void selectfail();
void Clean();
void Cleanabz(); //заполнение массива с номером строк 0
void strlong();
FILE* f;
int dstr = 10;
int nstr = 0;
//
int r;
int n = 10, ij = 0;
char fname[255];
//
char cs[15];
int spper = 1;
int flag = 0;
int abz = -1;
int flp = 1;
char abzz[2000];             // массив с номером строк (1-абзац, 0- обычная строка)
 
int main()
{
    Cleanabz();
    char c;
    selectfail();
    noformat(dstr);             // убираем лишние пробелы и переносы
    while (1) {
        system("CLS");
        puts("  ");
        puts("  ** Formatter **");
        puts("  ");
        puts("  1 - Select file");
        puts("  2 - Clean all file");
        puts("  3 - Change string length ");
        puts("  4 - No format");
        puts("  5 - Format ");
        puts("  6 - Paragraph ");
        puts("  0 - Exit");
        puts("  ");

        c = getchar();
        switch (c) {
        case '1':
            selectfail();
            break;
        case '2':
            Clean();
            break;
        case '3':
            strlong();
            break;
        case '4':
            Cleanabz();
            noformat(dstr);
            break;
        case '5':
            format(dstr);
            break;
        case '6':
            paragraph();
            break;
        case '0':
            return 0;
        }
    }

    getchar();
}

void format(int ds)
{
    f = fopen(fname, "r");
    char cha;
    char pred;
    int k = 0, ks = 1;
    // printf("%d",ds);
    // /*
    if (abz >= 0)
        k += 3;
    do {
        cha = fgetc(f);
        k++;

        if ((k % ds) == 0)
            ks++;

    } while (cha != EOF); // */
    // printf("ks=%d\n",ks);
    // printf("k=%d\n",k);
    if (abz >= ks)
        puts("Exceeds the number of lines");
    else
        flp = 0;

    rewind(f);
    puts("a");
    char mt[ks][ds];
    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ds; j++) {
            if (((i == abz) || (abzz[i] == 1))
                && (j == 0 || j == 1 || j == 2)) {
                cha = ' ';
                mt[i][j] = cha;
            } else {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
                //         chi=mt[i][j];
                while (cha == '\n') {
                    mt[i][j] = fgetc(f);
                    cha = mt[i][j];
                    //                       j++;
                    //                         puts("/ m n");
                }
                while (pred == cha && cha == ' ') {
                    mt[i][j] = fgetc(f);
                    cha = mt[i][j];
                    //                       puts("probel");
                }
                pred = cha;
            }
        }
    } // f
    fclose(f);
    printf("\n");
    printf("\n");

    f = fopen(fname, "w");
    fclose(f);

    f = fopen(fname, "r+");
    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ds; j++) {
            cha = mt[i][j];
            //        if (chi==(-1)) continue;
            if (cha == EOF)
                continue;
            else
                fwrite(&cha, sizeof cha, 1, f);
            //        printf("%d",j);
            //          printf("%c",cha);
        }
        fputs("\n", f);
    }
    abz = -1;
    fclose(f);
}

void noformat(int ds)
{
    // char str[ds];
    f = fopen(fname, "r");
    char cha;
    char pred;
    //   int chi;
    int k = 0, ks = 1;

    do {
        cha = fgetc(f);
        k++;
        if ((k % ds) == 0)
            ks++;
    } while (cha != EOF); // */
    // printf("ks=%d\n",ks);
    // printf("k=%d\n",k);
    nstr = ks;
    rewind(f);
    // puts("a");
    char mt[ks][ds];
    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ds; j++) {
            mt[i][j] = fgetc(f);
            cha = mt[i][j];
            //         chi=mt[i][j];
            while (cha == '\n') {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
                //                       j++;
                //                         puts("/ m n");
            }
            while (pred == cha && cha == ' ') {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
                //                      puts("probel");
            }
            pred = cha;
            //         if (cha==EOF) continue;
            //         if (chi==(-1)) continue;
        }
        // fputs("\n",f);
    } //
    fclose(f);
    // printf("\n");
    // printf("\n");

    f = fopen(fname, "w");
    fclose(f);

    f = fopen(fname, "r+");
    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ds; j++) {
            cha = mt[i][j];
            //        chi=mt[i][j];
            //        if (chi==(-1)) continue;
            if (cha == EOF)
                continue;
            else
                fwrite(&cha, sizeof cha, 1, f);
            //        printf("%d",j);
            //          printf("%c",cha);
        }
        // printf("%d\n",i);
        // fputs("\n",f);
    } //
    fclose(f);
}

void paragraph()
{
    int oi;

    puts("enter the line");
    scanf("%d", &oi);
    if (oi > 0 && oi <= nstr) {
        abz = oi - 1;
        abzz[abz] = 1; // отмечаем номер нужной строки в массиве
        format(dstr);
        flp = 0;
    } else {
        puts(" Error ");
    }
}

void Clean()
{
    system("CLS");
    f = fopen(fname, "w");
    fclose(f);
    // _getch();
}

void strlong()
{
    int dst;
    puts(" Enter new string length \n  ");
    scanf("%d", &dst);
    if (dst > 0 && dst < 100) {
        dstr = dst;
        format(dstr);
    } else {
        puts(" Error ");
    }
}

void Cleanabz()
{                                                          //функция удаления абзаца
    for (int i = 0; i < 2000; i++) {
        abzz[i] = 0;
    }
}

void selectfail()
{
    int flag = 0;
    while (flag == 0) {
        printf(" Enter filename \n");
        // gets(fname);
        scanf("%s", fname);
        if ((f = fopen(fname, "r")) == NULL) {
            printf("Error open file not faund \n ");
        } else {
            printf("Open file \n");
            flag = 1;
        }
    }
}