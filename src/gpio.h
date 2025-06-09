/**
 * @file gpio.h
 * @brief Hardware abstraction for GPIO operations.
 */

#ifndef GPIO_H
#define GPIO_H

/**
 * @brief Sets the given GPIO pin to high.
 *
 * @param pin GPIO pin number
 */
void gpio_set_pin(int pin);

/**
 * @brief Clears the given GPIO pin to low.
 *
 * @param pin GPIO pin number
 */
void gpio_clear_pin(int pin);

#endif // GPIO_H