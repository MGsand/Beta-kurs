#include <lib/functions.h>

int main()
{
    Cleanabz();
    char c;
    int ds= 40;
    selectfail();
    noformat(ds);
    save();
    while (1) {
        system("clear");
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
            ds=strlong();
            printsave();
            break;
        case '4':
            Cleanabz();
            printsave();
            noformat(ds);
            break;
        case '5':
            printsave();
            format(ds);
            break;
        case '6':
            paragraph();
            printsave();
            format(ds);
            break;
        case '0':
            return 0;
        }
    }

    getchar();

    return 0;
}
