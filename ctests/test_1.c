#include "ctest.h"
#include "functions.h"
#include <stdio.h>

CTEST(open_write_read, numbers_test)
{
    char text1[] = "123456789";

    char result_text1[11];

    FILE* f;
    char fname[] = "texttest.txt";

    f = fopen(fname, "w+");
    fputs(text1, f);
    rewind(f);
    fgets(result_text1, 11, f);
    fclose(f);

    char expected_text1[] = "123456789";
    ASSERT_STR(expected_text1, result_text1);
}

CTEST(open_write_read, text_test)
{
    char text1[] = "qwertyuiop asdfghjkl zxcvbnm";
    char text2[] = "QWERTYUIOP ASDFGHJKL ZXCVBNM";

    char result_text1[29];
    char result_text2[29];

    FILE* f;
    char fname[] = "texttest.txt";

    f = fopen(fname, "w+");
    fputs(text1, f);
    rewind(f);
    fgets(result_text1, 29, f);
    fclose(f);

    f = fopen(fname, "w+");
    fputs(text2, f);
    fclose(f);
    rewind(f);
    f = fopen(fname, "r");
    fgets(result_text2, 29, f);
    fclose(f);

    char expected_text1[] = "qwertyuiop asdfghjkl zxcvbnm";
    char expected_text2[] = "QWERTYUIOP ASDFGHJKL ZXCVBNM";

    ASSERT_STR(expected_text1, result_text1);
    ASSERT_STR(expected_text2, result_text2);
}

CTEST(open_write_read, symbols_test)
{
    char text1[25] = "!@#$%^&*()_+ []{}|/<>,.";
    char text2[5] = "   n";

    char result_text1[25];
    char result_text2[5];

    FILE* f;
    char fname[] = "texttest.txt";

    f = fopen(fname, "w+");
    fputs(text1, f);
    rewind(f);
    fgets(result_text1, 25, f);
    fclose(f);

    f = fopen(fname, "w+");
    fputs(text2, f);
    rewind(f);
    fgets(result_text2, 5, f);
    fclose(f);

    char expected_text1[] = "!@#$%^&*()_+ []{}|/<>,.";
    char expected_text2[] = "   n";

    ASSERT_STR(expected_text1, result_text1);
    ASSERT_STR(expected_text2, result_text2);
}

CTEST(open_write_read, strProb_test)
{
    char text1[2] = " ";

    char result_text1[2];

    FILE* f;
    char fname[] = "texttest.txt";

    f = fopen(fname, "w+");
    fputs(text1, f);
    rewind(f);
    fgets(result_text1, 2, f);
    fclose(f);

    char expected_text1[] = " ";

    ASSERT_STR(expected_text1, result_text1);
}

CTEST(functions, clean_test)
{
    char text1[] = "  vvedite     text";

    char result;

    FILE* f;
    char fname[] = "texttest.txt";

    f = fopen(fname, "w+");
    fputs(text1, f);
    fclose(f);
    
    Clean(fname);
        
    f = fopen(fname, "r");
    result=fgetc(f);
    fclose(f);
    
    const char expected = EOF;
    ASSERT_EQUAL(expected, result);
}

CTEST(functions, noformat_test)
{
    char text1[] = "  vvedite     text";
    char text2[] = "vvedite     text vvedite     text  vvedite     text";

    char result_text1[19];
    char result_text2[54];

    FILE* f;
    char fname[] = "texttest.txt";

    f = fopen(fname, "w+");
    fputs(text1, f);
    fclose(f);
    noformat(fname);
    f = fopen(fname, "r");
    fgets(result_text1, 14, f);
    fclose(f);

    f = fopen(fname, "w+");
    fputs(text2, f);
    fclose(f);
    noformat(fname);
    f = fopen(fname, "r");
    fgets(result_text2, 39, f);
    fclose(f);

    char expected_text1[] = " vvedite text";
    char expected_text2[] = "vvedite text vvedite text vvedite text";

    ASSERT_STR(expected_text1, result_text1);
    ASSERT_STR(expected_text2, result_text2);
}



CTEST(functions, format_test)
{
char text1[] = "vvedite text";
char result1_text1[12];
char result1_text2[4];
char result1_text3[2];
char result1_text4[11];

FILE* f;
char fname[] = "texttest.txt";

f = fopen(fname, "w+");
fputs(text1, f);
fclose(f);
format(fname, 10, 11);

f = fopen(fname, "r");
fgets(result1_text1, 12, f);
fgets(result1_text2, 4, f);
fgets(result1_text3, 2, f);
fgets(result1_text4, 11, f);
fclose(f);

char expected_text1[] = "vvedite te\n";
char expected_text2[] = "xt\n";
char expected_text3[] = "\n";
char expected_text4[] = "         1";

ASSERT_STR(expected_text1, result1_text1);
ASSERT_STR(expected_text2, result1_text2);
ASSERT_STR(expected_text3, result1_text3);
ASSERT_STR(expected_text4, result1_text4);
} 

CTEST(functions, format_different_stringlong_test)
{
char text1[] = "vvedite text vvedite text";
char result1_text1[13];
char result1_text2[13];
char result1_text3[5];
char result1_text4[2];
char result1_text5[11];

char result2_text1[27];
char result2_text2[2];
char result2_text3[11];

FILE* f;
char fname[] = "texttest.txt";

f = fopen(fname, "w+");
fputs(text1, f);
fclose(f);
format(fname, 11, 25);

f = fopen(fname, "r");
fgets(result1_text1, 13, f);
fgets(result1_text2, 13, f);
fgets(result1_text3, 5, f);
fgets(result1_text4, 2, f);
fgets(result1_text5, 11, f);
fclose(f);

f = fopen(fname, "w+");
fputs(text1, f);
fclose(f);
format(fname, 30, 25);

f = fopen(fname, "r");
fgets(result2_text1, 27, f);
fgets(result2_text2, 2, f);
fgets(result2_text3, 11, f);
fclose(f);

char expected_text1[] = "vvedite tex\n";
char expected_text2[] = "t vvedite t\n";
char expected_text3[] = "ext\n";
char expected_text4[] = "\n";
char expected_text5[] = "         1";

char expected2_text1[] = "vvedite text vvedite text\n";
char expected2_text2[] = "\n";
char expected2_text3[] = "         1";

ASSERT_STR(expected_text1, result1_text1);
ASSERT_STR(expected_text2, result1_text2);
ASSERT_STR(expected_text3, result1_text3);
ASSERT_STR(expected_text4, result1_text4);
ASSERT_STR(expected_text5, result1_text5);

ASSERT_STR(expected2_text1, result2_text1);
ASSERT_STR(expected2_text2, result2_text2);
ASSERT_STR(expected2_text3, result2_text3);
} 

