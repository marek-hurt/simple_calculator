/**
 * @file watchdog.h
 * @brief Software Watchdog Timer with timeout callback and system tick
 */

#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Function pointer type for the watchdog timeout callback.
 */
typedef void (*watchdog_callback_t)(void);

/**
 * @brief Initializes the software watchdog.
 *
 * This function sets the timeout value and registers a callback function
 * that will be called when the timeout is reached unless the watchdog is reset.
 *
 * @param timeout Timeout value in milliseconds.
 * @param callback Function to be called when the watchdog expires.
 */
void watchdog_init(uint32_t timeout, watchdog_callback_t callback);

/**
 * @brief Resets the watchdog timer.
 *
 * This function resets the internal elapsed time counter.
 * If the watchdog has already expired, it also clears the triggered flag.
 */
void watchdog_kick(void);

/**
 * @brief Simulates the passage of time and checks for timeout.
 *
 * Call this function periodically with the elapsed time since the last call
 * to simulate system tick updates. If the elapsed time exceeds the timeout,
 * the registered callback will be invoked (only once).
 *
 * @param elapsed_ms Elapsed time in milliseconds.
 */
void watchdog_tick(uint32_t elapsed_ms);

#endif // WATCHDOG_H