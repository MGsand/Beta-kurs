#include "functions.h"

FILE* f;

int dstr = 40;
int nstr = 0;

int r;
int n = 10, ij = 0;
char fname[255];

char cs[15];
int spper = 1;
int flag = 0;
int abz = -1;
int flp = 1;
int ksim;
char* p;
char abzz[2000];

void format(int ds)
{
    f = fopen(fname, "r");
    char cha;
    char pred;
    int k = 0, ks = 1;
    int stran = 0, ki = 0;
    if (abz >= 0)
        k += 3;
    do {
        cha = fgetc(f);
        k++;

        if ((k % ds) == 0)
            ks++;

    } while (cha != EOF);

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

                while (cha == '\n') {
                    mt[i][j] = fgetc(f);
                    cha = mt[i][j];
                }
                pred = cha;
                while (pred == cha && cha == ' ') {
                    mt[i][j] = fgetc(f);
                    cha = mt[i][j];
                }
            }
        }
    }
    fclose(f);
    printf("\n");
    printf("\n");

    f = fopen(fname, "w");
    fclose(f);

    f = fopen(fname, "r+");
    for (int i = 0; i < ks; i++) {
        ki++;
        for (int j = 0; j < ds; j++) {
            cha = mt[i][j];

            if (cha == EOF)
                continue;
            else
                fwrite(&cha, sizeof cha, 1, f);
        }
        if (ki == 40) {
            stran++;
            fprintf(f, "\n         %d", stran);
            ki = 0;
        }
        fputs("\n", f);
    }
    stran++;
    if (ki != 0) {
        fprintf(f, "         %d", stran);
    }

    abz = -1;
    fclose(f);
}

void noformat(int ds)
{
    f = fopen(fname, "r");
    char cha;
    char pred;
    int k = 0, ks = 1;

    do {
        cha = fgetc(f);
        k++;
        if ((k % ds) == 0)
            ks++;
    } while (cha != EOF);
    nstr = ks;
    ksim = k;
    rewind(f);

    char mt[ks][ds];

    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ds; j++) {
            mt[i][j] = fgetc(f);
            cha = mt[i][j];
            while (cha == '\n') {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
            }
            pred = cha;
            while (pred == cha && cha == ' ') {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
            }
        }
    }
    fclose(f);

    f = fopen(fname, "w");
    fclose(f);

    f = fopen(fname, "r+");
    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ds; j++) {
            cha = mt[i][j];
            if (cha == EOF)
                continue;
            else
                fwrite(&cha, sizeof cha, 1, f);
        }
    }
    fclose(f);
}

void paragraph()
{
    int oi;

    puts("enter the line");
    scanf("%d", &oi);
    if (oi > 0 && oi <= nstr) {
        abz = oi - 1;
        abzz[abz] = 1;
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
{
    for (int i = 0; i < 2000; i++) {
        abzz[i] = 0;
    }
}

void save()
{
    f = fopen(fname, "r");
    char cha;
    int y = 0;
    for (int i = 0; i < ksim; i++) {
        p[i] = fgetc(f);
        cha = p[i];
    }
    if (cha == ' ')
        y++;

    fclose(f);
}

void printsave()
{
    char cha;
    f = fopen(fname, "w");
    fclose(f);

    f = fopen(fname, "r+");
    for (int i = 0; i < ksim; i++) {
        cha = p[i];

        fwrite(&cha, sizeof cha, 1, f);
    }
    fclose(f);
}

void selectfail()
{
    int flag = 0;
    while (flag == 0) {
        printf(" Enter filename \n");

        scanf("%s", fname);
        if ((f = fopen(fname, "r")) == NULL) {
            printf("Error open file not faund \n ");
        } else {
            printf("Open file \n");
            flag = 1;
        }
    }
}

