/* file test_example.c */

#include <stdio.h>
#include "punit.h"

int foo;
int bar;

static void setup()
{
    foo = 7;
    bar = 4;
}

static void teardown()
{
}

static char * test_foo()
{
    pu_assert("error, foo != 7", foo == 7);
    return 0;
}

static char * test_bar()
{
    pu_assert("error, bar != 5", bar == 5);
    return 0;
}

static char * all_tests()
{
    pu_run_test(test_foo, "test_foo");
    pu_run_test(test_bar, "test_bar");
    return 0;
}

int main(int argc, char **argv)
{
    return pu_run_tests(&all_tests);
}
