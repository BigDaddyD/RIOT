/*
 * Copyright (C) 2015 Kushal Singh <kushal.spiderman.singh@gmail.com>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include "tests-hash_string.h"
#include "hash_string.h"

static void test_hash_value(void)
{
    TEST_ASSERT_EQUAL_INT(177621, hash_string((unsigned char *)"0"));
    TEST_ASSERT_EQUAL_INT(685012521, hash_string((unsigned char *)"0123456789ab"
                                                "cde-0123456789abcde-0123456789"
                                                "abcde-0123456789abcde-"));
    TEST_ASSERT_EQUAL_INT(900068641, hash_string((unsigned char *)"Frank jagt "
                                                "im komplett verwahrlosten Taxi"
                                                " quer durch Bayern"));
    TEST_ASSERT_EQUAL_INT(1857959484, hash_string((unsigned char *)"12A5B6cd_"));
    TEST_ASSERT_EQUAL_INT(5381, hash_string((unsigned char *)""));
}

Test *tests_hash_string_tests(void)
{
    EMB_UNIT_TESTFIXTURES(fixtures) {
        new_TestFixture(test_hash_value),
    };

    EMB_UNIT_TESTCALLER(hash_string_tests, NULL, NULL, fixtures);

    return (Test *)&hash_string_tests;
}

void tests_hash_string(void)
{
    TESTS_RUN(tests_hash_string_tests());
}
