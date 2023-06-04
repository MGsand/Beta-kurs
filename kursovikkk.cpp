#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct tov {char name200]; float c; int kol;} t1;
void selectfail();
void Clean(char* name);
void strlong();
// void addtostart(char *name);
// void  addtoend(char *name);
// void delete_t(char *name);
FILE* f;
int dstr = 10;
int nstr = 0;
char freename[6];
// f
// char fname[]="a.txt";
char stroka[] = "one two";
//
char fname[10];
char* T;
//	T=(int * ) malloc(m*sizeof(int));
// string fname();
int flag = 0;
int n, ij = 0;
int main()
{
    char c;
    selectfail();

    /* do {
        for ( n=0; n<dstr; n++){
            ch=fgetc(f);
    //       stroka
           // puts(n);
            printf("%d", n);
       }
    //   fprintf(f,"\n");
         fputs("\n",f);
      nstr++;
      printf("%d\n",nstr);
     }
    while (ch!=EOF);
    */

    //
    /*do {
        for ( n=0; n<dstr; n++){
            ch=fgetc(f);
            }
    //   nstr++;

     }
    while (ch!=EOF); */
    puts("1");
    T = (char*)malloc(n * sizeof(char));
    puts("2");

    //
    /* for ( int i=0; i<n; i++){
            T[i]=fgetc(f);
            if( (i % dstr)==0){
                 nstr++;
                 }

           // puts(n);
     //
     //      printf("%s", T[i]);
       } */
    puts("3");
    n = n + n * nstr;
    printf("%d\n", n);
    printf("%d\n", nstr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < nstr; j++) {
            fprintf(f, "%s", &T[ij]);
            ij++;
        }
        fputs("\n", f);
    }
    // */
    // puts("4");
    fclose(f);
    /*
   f=fopen(fname,"rb+");
   //rewind(f);
   do {
       for ( n=0; n<dstr; n++){
           ch=fgetc(f);
          stroka
          // puts(n);
           printf("%d", n);
      }
   //   fprintf(f,"\n");
        fputs("\n",f);
     nstr++;
     printf("%d\n",nstr);
    }
   while (ch!=EOF);
    fclose(f);
   //
    */
    // getch();
    while (1) { // system("CLS");
        puts("  1 - Select file");
        puts("  2 - Clean all file");
        puts("  3 - Change string length ");
        puts("  0 - Exit");

        c = getchar();
        switch (c) { // case '1':
            //         input("file1.dat");
            //     closegraph();
        case '1':
            selectfail();
            break;
        case '2':
            Clean(fname);
            break;
        case '3':
            strlong();
            break;
            //      case '4':addtostart(fname);break;
            //      case '5':addtoend(fname);break;
            //      case '6':delete_t(fname);break;
        case '0':
            return 0;
        default:
            puts("Error");
        }
    }

    getchar();
}

//}
void Clean(char* name)
{
    FILE* tf;
    system("CLS");
    tf = fopen(name, "w+");
    fclose(tf);
    getchar();
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

