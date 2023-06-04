#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void noformat(int ds);
void selectfail();
void Clean();
void strlong();
FILE* f;
int dstr = 20;
int nstr = 0;
char freename[6];
// string *as;
//
// char fname[]="a.txt";
char stroka[] = "one two";
//
int r;
int n = 10, ij = 0;
char fname[255];
//
char cs[15];
// char tcs[r];
char* T;
int spper = 1;
int flag = 0;

int main()
{
    char c;
    selectfail();

    //
    r = 15;

    puts("3");

    while (1) { // system("CLS");
        puts("  1 - Select file");
        puts("  2 - Clean all file");
        puts("  3 - Change string length ");
        puts("  4 - No format");
        puts("  0 - Exit");

        c = getchar();
        switch (c) { // case '1':
            //         input("file1.dat");
            //     closegraph();
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
        case '0':
            return 0;
        default:
            puts("Error");
        }
    }

    getchar();
}

void noformat(int ds)
{
    // char str[ds];
    f = fopen(fname, "r");
    char cha;
    char pred;
    //    std::string txt;
    //    std::string st;
    //     char  *st[ds];
    int k = 0, ks = 1;
    /*          do {                              // string
            //cha=fgetc(f);
            cha=fgetc(f);
            k++;
            txt+=cha;
     }
    while (cha!=EOF);
    //char chi;
    fputs("\n",f);
              for (int i=0;i<k;i++){
    //              cha=txt(i);
    //             char chi = const_cast<char*>(txt.(i));
    //              fputs(cha,f);
    //                char * cha = txt.data(i);
                  printf("%s",ds);
            }  */

    //
    printf("%d", ds);
    // /*

    do {
        cha = fgetc(f);
        k++;
        if ((k % ds) == 0)
            ks++;
    } while (cha != EOF); // */
    printf("ks=%d\n", ks);
    printf("k=%d\n", k);

    rewind(f);
    puts("a");
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
                puts("/ m n");
            }
            while (pred == cha && cha == ' ') {
                mt[i][j] = fgetc(f);
                cha = mt[i][j];
                puts("probel");
            }
            pred = cha;
            //         if (cha==EOF) continue;
            //         if (chi==(-1)) continue;
        }
        // fputs("\n",f);
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
            //        chi=mt[i][j];
            //        if (chi==(-1)) continue;
            if (cha == EOF)
                continue;
            else
                fwrite(&cha, sizeof cha, 1, f);
            //        printf("%d",j);
            printf("%c", cha);
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
    puts(" Enter new string length \n  ");
    scanf("%d", &dstr);
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

