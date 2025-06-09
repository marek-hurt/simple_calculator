
/**
 * @file led.c
 * @brief Simple LED control using GPIO
 */

#include "gpio.h"

#define LED_PIN 5

/**
 * @brief Turns the LED on by setting the GPIO pin.
 */
void led_on(void) {
    gpio_set_pin(LED_PIN);
}

/**
 * @brief Turns the LED off by clearing the GPIO pin.
 */
void led_off(void) {
    gpio_clear_pin(LED_PIN);
}