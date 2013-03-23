/**
 * @file punit.h
 * @brief PUnit, a portable unit testing framework for C.
 *
 * Inspired by: http://www.jera.com/techinfo/jtns/jtn002.html
 */

/* Copyright (c) 2012, Ninjaware Oy, Olli Vanhoja <olli.vanhoja@ninjaware.fi>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once
#ifndef PUNIT_H
#define PUNIT_H

#include <stdio.h>
#include <string.h>
#if PU_LMATH == 1
#include <math.h>
#endif

#define pu_assert(message, test) do { if (!(test)) { \
        printf("FAILED: %s:%d: (%s)\n",              \
            __FILE__, __LINE__, #test);              \
        return message; }                            \
} while (0)

#define pu_assert_equal(message, left, right) do { if (!(left == right)) { \
        printf("FAILED: %s:%d: %i == %i\n",                                \
            __FILE__, __LINE__, left, right);                              \
        return message; }                                                  \
} while(0)

#define pu_assert_str_equal(message, left, right) do {  \
    if (strcmp(left, right) != 0) {                     \
        printf("FAILED: %s:%d: \"%s\" equals \"%s\"\n", \
            __FILE__, __LINE__, left, right);           \
    return message; }                                   \
} while (0)

#if PU_LMATH == 1
#define pu_assert_double_equal(message, left, right, delta) do {            \
    if (!(fabs((double)left - (double)right) < (double)delta)) {            \
        printf("FAILED: %s:%d: %f is approximately equal to %f (d = %f)\n", \
            __FILE__, __LINE__, left, right, delta);                        \
        return message; }                                                   \
} while(0)
#endif

#define pu_assert_fail(message) do { printf("FAILED: Assert fail\n"); \
    return message;                                                   \
} while (0)

#define pu_run_test(test) do { char * message;                           \
                               printf("-%s\n", #test);                   \
                               setup();                                  \
                               message = test(); pu_tests_count++;       \
                               teardown();                               \
                               if (message) { printf("\t%s\n", message); \
                               } else pu_tests_ok++;                     \
                             } while (0)

#define PU_TEST_BUILD 1 /*!< This definition can be used to exclude included
                         * files and souce code that are not needed for unit
                         * tests. */

extern int pu_tests_ok; /*!< Global tests ok counter. */
extern int pu_tests_count; /*!< Global tests counter. */

int pu_run_tests(void (*all_tests)(void));

#endif /* PUNIT_H */
