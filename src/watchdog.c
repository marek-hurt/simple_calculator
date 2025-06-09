/**
 * @file watchdog.c
 * @brief Software Watchdog Timer implementation with callback on timeout.
 */

#include "watchdog.h"

/**
 * @brief Timeout value in milliseconds.
 */
static uint32_t s_timeout_ms = 0;

/**
 * @brief Elapsed time since last watchdog reset.
 */
static uint32_t s_elapsed_ms = 0;

/**
 * @brief Pointer to the timeout callback function.
 */
static watchdog_callback_t s_callback = 0;

/**
 * @brief Indicates whether the watchdog has already expired.
 */
static bool s_triggered = false;

void watchdog_init(uint32_t timeout, watchdog_callback_t callback) {
    s_timeout_ms = timeout;
    s_elapsed_ms = 0;
    s_callback = callback;
    s_triggered = false;
}

void watchdog_kick(void) {
    s_elapsed_ms = 0;
    s_triggered = false;
}

void watchdog_tick(uint32_t elapsed_ms) {
    if (s_triggered) return;

    s_elapsed_ms += elapsed_ms;

    if (s_elapsed_ms >= s_timeout_ms) {
        s_triggered = true;
        if (s_callback) {
            s_callback();
        }
    }
}