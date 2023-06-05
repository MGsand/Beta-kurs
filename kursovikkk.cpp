#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
void format(int ds); // есть изменения в форматировании связанные с абзацем
void noformat(int ds);
void paragraph(); //функция для выделения абзаца
void selectfail();
void Clean();
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
int abz = -1; //номер абзаца если он меньше 0 то абзаца нет
int flp = 1;

int main()
{
    char c;
    selectfail();
    noformat(dstr);
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
        puts("Exceeds the number of lines"); // проверка, сравнение строки 
                                             // абзаца с количеством строк
    else
        flp = 0;

    rewind(f);
    puts("a");
    char mt[ks][ds];
    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ds; j++) {
            if ((i == abz)  && (j == 0 || j == 1  || j == 2)) { // заполнение нужной строки абзацем
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
    } //
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
{ //функция  добавления абзаца
    int oi;

    puts("enter the line");
    scanf("%d", &oi);
    if (oi > 0 && oi <= nstr) {
        abz = oi - 1;
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

void strlong() // изменение длины строки
{
    int dst;
    puts(" Enter new string length \n  ");
    scanf("%d", &dst);
    if (dst > 0 && dst < 100) {
        dstr = dst;
        format(dstr); // форматирование если всё хорошо
    } else {
        puts(" Error ");
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