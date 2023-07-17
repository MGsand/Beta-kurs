#include "ctest.h"
#include <../../src/lib/functions.h>

CTEST(functions_test, functions)
{
    int p_true, r = 40;

    format(&p_true);

    int expected_p = r;

    // Then

    ASSERT_DBL_NEAR_TOL(expected_p, p_true, 1);
}

