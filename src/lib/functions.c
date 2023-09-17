#include <lib/functions.h>
#include <string.h>

FILE* f;

int ds = 40;
int nstr = 0;

int r;
int n = 10, ij = 0;
char chaa;
char fname[255];

char cs[15];
int spper = 1;
int flag = 0;
int abz = -1;
int flp = 1;
int ksim;
char* p;
char abzz[2000];

void format(char fname[255], int ds)
{
    f = fopen(fname, "r");
    char cha;
    char pred;
    int k = 0, ks = 1;
    int stran = 1, ki = 0;
    if ((abz >= 0) && (abz <= ks))
        k += 3;

    do {
        cha = fgetc(f);
        k++;
        if ((k % ds) == 0)
            ks++;
    } while (cha != EOF);
    nstr = ks;
    ksim = k;
    rewind(f);
    printf("ds %d\n", ds);
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
                while (pred == cha && cha == ' ') {
                    mt[i][j] = fgetc(f);
                    cha = mt[i][j];
                }
                pred = cha;
            }
        }
    }
    fclose(f);

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
        fputs("\n", f);
        if (ki == 40) {
            fprintf(f, "\n         %d", stran);
            fputs("\n", f);
            stran++;
            ki = 0;
        }
        abz = -1;
    }
    if (ki != 0) {
        fputs("\n", f);
        fprintf(f, "         %d", stran);
    }

    fclose(f);
}

void noformat(char fname[255])
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
            while (pred == cha && cha == ' ') {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
            }
            pred = cha;
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
        fo();
        flp = 0;
    } else {
        puts(" Error ");
    }
}

void Clean()
{
    f = fopen(fname, "w");
    fclose(f);
}

int strlong()
{
    int dst;
    puts(" Enter new string length \n  ");
    scanf("%d", &dst);
    if (dst > 0 && dst < 100) {
        ds = dst;
        fo();
    } else {
        puts(" Error ");
    }
    return dst;
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
    p = (char*)malloc(ksim * sizeof(char));
    int y = 0;
    for (int i = 0; i < ksim; i++) {
        p[i] = fgetc(f);
        chaa = p[i];
    }
    if (chaa == ' ')
        y++;
    fclose(f);
}

void printsave()
{
    f = fopen(fname, "w");
    fclose(f);

    f = fopen(fname, "r+");
    for (int i = 0; i < ksim; i++) {
        chaa = p[i];

        fwrite(&chaa, sizeof chaa, 1, f);
    }
    fclose(f);
}

void selectfail()
{
    printf(" Enter filename \n");
    scanf("%s", fname);
    while ((f = fopen(fname, "r")) == NULL) {
        printf("Error open, file not faund \n ");
        printf(" Enter filename \n");
        scanf("%s", fname);
    }
    printf("Open file \n");
}

void nof()
{
    noformat(fname);
}

void fo()
{
    printsave();
    format(fname, ds);
}
