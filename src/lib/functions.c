#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void format(char* fname, int ds, int kstr)
{
    FILE* f;
    f = fopen(fname, "r");
    if (f == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
    char cha;
    char pred = ' ';
    int k = 0, ks = 0;
    int stran = 1, ki = 0;
    int nstr;
    do {
        cha = fgetc(f);
        k++;
        if ((k % ds) == 0)
            ks++;
    } while (cha != EOF);
    ks++;
    nstr = ks;
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
            while (pred == cha && cha == ' ') {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
            }
            pred = cha;
        }
    }

    fclose(f);

    f = fopen(fname, "w+");
    if (f == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
    for (int i = 0; i < ks; i++) {
        ki++;
        for (int j = 0; j < ds; j++) {
            cha = mt[i][j];
            if (cha == EOF)
                continue;
            else
                fwrite(&cha, sizeof cha, 1, f);
        }
        fputs("\n", f);
        if (ki == 40) {
            fprintf(f, "\n         %d", stran);
            fputs("\n", f);
            stran++;
            ki = 0;
        }
    }
    if (ki != 0) {
        fputs("\n", f);
        fprintf(f, "         %d", stran);
    }

    fclose(f);
}

int noformat(char* fname)
{
    FILE* f;
    f = fopen(fname, "r");
    if (f == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
    char cha;
    char pred;
    int k = 0, ks = 1, ds = 40;

    do {
        cha = fgetc(f);
        k++;
        if ((k % ds) == 0)
            ks++;
    } while (cha != EOF);

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
            while (pred == cha && cha == ' ') {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
            }
            pred = cha;
        }
    }
    fclose(f);

    f = fopen(fname, "w+");
    if (f == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
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
    return k;
}

void Clean(char* fname)
{
    puts("1 ");
    FILE* f;
    f = fopen(fname, "w");
    if (f == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
    fclose(f);
}

int strlong(char* fname, int ds)
{
    int dst;
    puts(" Enter new string length \n  ");
    scanf("%d", &dst);
    if (dst > 9 && dst < 100) {
        return dst;
    } else {
        puts(" Error ");
        return ds;
    }
}

void save(char* fname, char* p, int ks)
{
    FILE* f;
    f = fopen(fname, "r");
    if (f == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
    for (int i = 0; i < (ks); i++) {
        p[i] = fgetc(f);
    }
    fclose(f);
}

void printsave(char* fname, char* p, int ks)
{
    FILE* f;
    char chaa;

    f = fopen(fname, "w+");
    if (f == NULL) {
        printf("Error opening file for reading and writing.\n");
        return;
    }
    for (int i = 0; i < (ks); i++) {
        chaa = p[i];
        if (chaa != EOF)
            fwrite(&chaa, sizeof chaa, 1, f);
    }
    fclose(f);
}

void selectfile(char* fname)
{
    FILE* f;
    printf(" Enter filename \n");
    scanf("%s", fname);
    while ((f = fopen(fname, "r")) == NULL) {
        printf("Error open, file not faund \n ");
        printf(" Enter filename \n");
        scanf("%s", fname);
    }
    printf("Open file \n");
}
