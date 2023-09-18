#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c;
    char fn[256];
    char* p = NULL;
    int ksim;
    int ds = 40;
    int kst;
    int e = 0;
    selectfile(fn);
    ksim = noformat(fn);
    kst = ksim / ds;
    p = (char*)malloc((ksim) * sizeof(char));
    if (p == NULL) {
        puts("Failed to allocate memory");
        return 1;
    }
    save(fn, p, ksim);
    while (1) {
        // system("clear");
        puts("  ");
        puts("  ** Formatter **");
        puts("  ");
        puts("  1 - Select file");
        puts("  2 - Clean all file");
        puts("  3 - Change string length ");
        puts("  4 - No format");
        puts("  5 - Format ");
        puts("  0 - Exit");
        puts("  ");

        c = getchar();
        switch (c) {
        case '1':
            free(p);
            p = NULL;
            selectfile(fn);
            ksim = noformat(fn);
            kst = ksim / ds;
            p = (char*)malloc((ksim) * sizeof(char));
            if (p == NULL) {
                puts("Failed to allocate memory");
                return 1;
            }
            save(fn, p, ksim);
            printsave(fn, p, ksim);
            break;
        case '2':
            Clean(fn);
            break;
        case '3':
            ds = strlong(fn, ds);
            kst = ksim / ds;
            printsave(fn, p, ksim);
            format(fn, ds, kst);
            break;
        case '4':
            printsave(fn, p, ksim);
            noformat(fn);
            break;
        case '5':
            printsave(fn, p, ksim);
            format(fn, ds, kst);
            break;
        case '0':
            free(p);
            p = NULL;
            return 0;
        }
    }

    getchar();

    return 0;
}
