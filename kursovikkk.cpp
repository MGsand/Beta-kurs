#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
void selectfail();
void pars(char stro[], int n);
void Clean();
FILE* f;
int dstr = 10;
// char freename[6];
// string *as;
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
    //   char ch;
    selectfail();

    //
    r = 15;
    //                                     format(dstr);

    puts("3");

    while (1) { // system("CLS");
        puts("  1 - Select file");
        puts("  2 - Clean all file");
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
        case '0':
            return 0;
        default:
            puts("Error");
        }
    }

    getchar();
}

void Clean()
{
    system("CLS");
    f = fopen(fname, "w");
    fclose(f);
    // _getch();
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

