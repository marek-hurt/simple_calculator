/**
 * @file test_led.c
 * @brief Unit tests for the LED module using mocked GPIO
 */

#include "unity.h"
#include "led.h"
#include "mock_gpio.h"

void setUp(void) {
    // Runs before each test
}

void tearDown(void) {
    // Runs after each test
}

/**
 * @test LED should turn on by calling gpio_set_pin with correct pin.
 */
void test_led_on_should_call_gpio_set_pin(void) {
    gpio_set_pin_Expect(5); // Expect that gpio_set_pin(5) will be called
    led_on();
}

/**
 * @test LED should turn off by calling gpio_clear_pin with correct pin.
 */
void test_led_off_should_call_gpio_clear_pin(void) {
    gpio_clear_pin_Expect(5); // Expect that gpio_clear_pin(5) will be called
    led_off();
}