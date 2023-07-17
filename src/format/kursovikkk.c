#include "functions.h"

int main()
{
    Cleanabz();
    char c;

    int dstr_temp = 0;

    selectfail();
    noformat(dstr_temp);
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
            noformat(dstr_temp);
            break;
        case '5':
            format(dstr_temp);
            break;
        case '6':
            paragraph();
            break;
        case '0':
            return 0;
        }
    }

    getchar();

    return 0;
}
