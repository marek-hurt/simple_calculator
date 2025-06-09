/**
 * @file test_watchdog.c
 * @brief Unit tests for the software watchdog timer module
 */

#include "unity.h"
#include "watchdog.h"

static bool callback_called = false;

/**
 * @brief Fake callback used to verify that the watchdog triggered.
 */
void fake_callback(void) {
    callback_called = true;
}

/**
 * @brief Setup runs before each test. Resets callback flag.
 */
void setUp(void) {
    callback_called = false;
}

/**
 * @brief Tear down runs after each test. Not used here.
 */
void tearDown(void) {
    // Nothing to clean up
}

/**
 * @test Watchdog should call the callback once after the timeout is reached.
 */
void test_watchdog_should_call_callback_on_timeout(void) {
    watchdog_init(100, fake_callback);
    watchdog_tick(50);
    TEST_ASSERT_FALSE(callback_called);
    watchdog_tick(60); // Total 110 > 100 → should trigger
    TEST_ASSERT_TRUE(callback_called);
}

/**
 * @test Watchdog should reset if kicked before timeout.
 */
void test_watchdog_should_not_call_callback_if_kicked(void) {
    watchdog_init(100, fake_callback);
    watchdog_tick(50);
    watchdog_kick(); // Reset
    watchdog_tick(90); // Still below timeout
    TEST_ASSERT_FALSE(callback_called);
    watchdog_tick(15); // Total 105 after reset → should now trigger
    TEST_ASSERT_TRUE(callback_called);
}

/**
 * @test Callback should only be called once, even after multiple tick calls.
 */
void test_watchdog_callback_called_only_once(void) {
    watchdog_init(100, fake_callback);
    watchdog_tick(150); // Exceeds timeout
    TEST_ASSERT_TRUE(callback_called);

    callback_called = false;
    watchdog_tick(50); // Already triggered; callback should not be called again
    TEST_ASSERT_FALSE(callback_called);
}

/**
 * @test Watchdog should handle NULL callback gracefully.
 */
void test_watchdog_init_with_null_callback(void) {
    watchdog_init(100, NULL);
    watchdog_tick(120); // Should timeout, but no callback to call
    TEST_ASSERT_TRUE(true); // Just ensure no crash
}

/**
 * @test Watchdog should trigger even if single tick exceeds timeout.
 */
void test_watchdog_tick_exceeds_timeout_immediately(void) {
    watchdog_init(50, fake_callback);
    watchdog_tick(100); // One large tick → should trigger
    TEST_ASSERT_TRUE(callback_called);
}

/**
 * @test Watchdog should be reset after timeout if kicked again.
 */
void test_watchdog_kick_after_timeout_resets(void) {
    watchdog_init(100, fake_callback);
    watchdog_tick(120); // Trigger once
    TEST_ASSERT_TRUE(callback_called);

    // Reset
    callback_called = false;
    watchdog_kick();

    // Should start from zero again
    watchdog_tick(50);
    TEST_ASSERT_FALSE(callback_called);
    watchdog_tick(60); // Now exceed again
    TEST_ASSERT_TRUE(callback_called);
}