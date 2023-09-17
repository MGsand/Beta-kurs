#include "ctest.h"
#include <lib/functions.h>

CTEST(functions, numbers_test)
{
 char text1[] = "123456789";
 
 char result_text1[11];
 
 FILE* f;
 char fname[] = "texttest.txt";
 
 f = fopen(fname, "w+");
 fputs(text1, f);
 rewind(f);
 fgets(result_text1,11,f);
 fclose(f);
 
 char expected_text1[] = "123456789";
 ASSERT_STR(expected_text1, result_text1);
}

CTEST(functions, text_test)
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

CTEST(functions, symbols_test)
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

CTEST(functions, strProb_test)
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

