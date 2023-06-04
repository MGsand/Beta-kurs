#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
void format(int ds);
void noformat(int ds);
void selectfail();
void Clean();
void strlong();
FILE* f;
int dstr = 10;
int nstr = 0;
char stroka[] = "one two";
//
int r;
int n = 10, ij = 0;
char fname[255];
//
char cs[15];
int spper = 1;
int flag = 0;

int main()
{
    char c;
    selectfail();
    while (1) {
        system("CLS");
        puts("  1 - Select file");
        puts("  2 - Clean all file");
        puts("  3 - Change string length ");
        puts("  4 - No format");
        puts("  5 - Format ");
        puts("  0 - Exit");

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
    //   int chi;
    int k = 0, ks = 1;

    do {
        cha = fgetc(f);
        k++;
        if ((k % ds) == 0)
            ks++;
    } while (cha != EOF);
    // printf("ks=%d\n",ks);
    // printf("k=%d\n",k);

    rewind(f);
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
        }
    }
    fclose(f);
    // printf("\n");
    // printf("\n");

    f = fopen(fname, "w");
    fclose(f);

    f = fopen(fname, "r+");
    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ds; j++) {
            cha = mt[i][j];
            //       chi=mt[i][j];
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
    //     int d;
    int ssh = 1;
    //     int chi[4];
    //     int ch;
    while (ssh == 1) {
        puts(" Enter new string length \n  ");
        //     scanf("%s", chi);
        scanf("%d", &dst);
        //      printf("%s", chi);
        if (dst > 0 && dst < 100) {
            dstr = dst;
            format(dstr);
            ssh = 0;
        } else {
            puts(" Error ");
        }
        ssh = 0;
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


