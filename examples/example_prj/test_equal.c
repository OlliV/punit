/* file test_example.c */

#include <stdio.h>
#include "punit.h"

static void setup()
{
}

static void teardown()
{
}

static char * test_ok()
{
    pu_assert_equal("Values are equal", 4, 4);
    return 0;
}

static char * test_fail()
{
    pu_assert_equal("Values are equal", 4, 5);
    return 0;
}

static void all_tests()
{
    pu_run_test(test_ok);
    pu_run_test(test_fail);
}

int main(int argc, char **argv)
{
    return pu_run_tests(&all_tests);
}
