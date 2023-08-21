#include "ctest.h"
#include <../../src/lib/functions.h>

CTEST(functions, noformat_test)
{
    char text1[] = "  vvedite   \n  text";
    char text2[] = "  vvedite   \n  text vvedite     text  vvedite   \n  text";

    char result_text1[13];
    char result_text2[39];

    FILE* f;
    char fname[] = "a.txt";

    f = fopen(fname, "w+");
    fputs(text1, f);
    noformat(40);
    rewind(f);
    fread(result_text1, 1, 13, f);
    fclose(f);

    f = fopen(fname, "w+");
    fputs(text2, f);
    noformat(40);
    rewind(f);
    fread(result_text2, 1, 39, f);
    fclose(f);

    char expected_text1[] = "vvedite text";
    char expected_text2[] = "vvedite text vvedite text vvedite text";

    ASSERT_STR(expected_text1, result_text1);
    ASSERT_STR(expected_text2, result_text2);
}

CTEST(functions, format_test)
{
    char text1[] = "vvedite text vvedite text";
    char text2[] = "vvedite text vvedite text vvedite text";
    ;

    char result_text1[27];
    char result_text2[59];

    FILE* f;
    int abz;
    char abzz[2000];

    f = fopen("a.txt", "w+");
    fputs(text1, f);
    format(20);
    rewind(f);
    fread(result_text1, 1, 27, f);
    fclose(f);

    f = fopen("a.txt", "w+");
    fputs(text1, f);
    abzz[1] = 1;
    abzz[2] = 1;
    format(20);
    rewind(f);
    fread(result_text1, 1, 59, f);
    fclose(f);

    char expected_text1[] = "vvedite text vvedite\n text";
    char expected_text2[]
            = "vvedite text vvedite\n   text vvedite text \n   vvedite text";

    ASSERT_STR(expected_text1, result_text1);
    ASSERT_STR(expected_text2, result_text2);
}

CTEST(functions, save_test)
{
    char text2[] = " vvedite \n text";
    char text1[] = "vvedite   \n \n text";

    char* result_text1;
    char* result_text2;

    FILE* f;
    char fname[] = "a.txt";
    char* p;
    int ksim;

    ksim = 18;
    f = fopen(fname, "w+");
    fputs(text1, f);
    fclose(f);
    save();
    for (int i = 0; i < ksim; i++) {
        result_text1[i] = p[i];
    }

    ksim = 15;
    f = fopen(fname, "w+");
    fputs(text2, f);
    fclose(f);
    save();
    for (int i = 0; i < ksim; i++) {
        result_text2[i] = p[i];
    }

    char expected_text1[]
            = {'v',
               'v',
               'e',
               'd',
               'i',
               't',
               'e',
               ' ',
               ' ',
               ' ',
               '\n',
               ' ',
               '\n',
               ' ',
               't',
               'e',
               'x',
               't'};
    char expected_text2[]
            = {' ',
               'v',
               'v',
               'e',
               'd',
               'i',
               't',
               'e',
               ' ',
               '\n',
               ' ',
               't',
               'e',
               'x',
               't'};

    ASSERT_DATA(expected_text1, 18, result_text1, 18);
    ASSERT_DATA(expected_text2, 15, result_text2, 15);
}

