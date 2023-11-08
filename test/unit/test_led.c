#include <unity.h>
#include "port_led.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_led(void)
{
    TEST_ASSERT_EQUAL(port_led_gpio_setup(), 0);
    TEST_ASSERT_FALSE(port_led_get());

    TEST_ASSERT_EQUAL(port_led_on(), 0);
    TEST_ASSERT_TRUE(port_led_get());

    TEST_ASSERT_EQUAL(port_led_off(), 0);
    TEST_ASSERT_FALSE(port_led_get());

    TEST_ASSERT_EQUAL(port_led_toggle(), 0);
    TEST_ASSERT_TRUE(port_led_get());
    TEST_ASSERT_EQUAL(port_led_toggle(), 0);
    TEST_ASSERT_FALSE(port_led_get());
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_led);
    return UNITY_END();
}
