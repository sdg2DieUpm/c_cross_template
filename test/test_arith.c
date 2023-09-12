#include <unity.h>
#include "arith.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_add(void)
{
    TEST_ASSERT_TRUE(add(1, 2) == 3);
    TEST_ASSERT_EQUAL(add(1, 2), 3);
}

void test_sub(void)
{
    TEST_ASSERT_TRUE(sub(1, 2) == -1);
    TEST_ASSERT_EQUAL(sub(1, 2), -1);
}

void test_mul(void)
{
    TEST_ASSERT_TRUE(mul(1, 2) == 2);
    TEST_ASSERT_EQUAL(mul(1, 2), 2);
}

void test_div(void)
{
    TEST_ASSERT_TRUE(div(1, 2) == 0);
    TEST_ASSERT_EQUAL(div(1, 2), 0);
}

void test_mod(void)
{
    TEST_ASSERT_TRUE(mod(1, 2) == 1);
    TEST_ASSERT_EQUAL(mod(1, 2), 1);
    // error on purpose
    TEST_ASSERT_EQUAL_MESSAGE(mod(1, 2), 2, "mod(1, 2) should be 1");
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_add);
    RUN_TEST(test_sub);
    RUN_TEST(test_mul);
    RUN_TEST(test_div);
    RUN_TEST(test_mod);
    return UNITY_END();
}
