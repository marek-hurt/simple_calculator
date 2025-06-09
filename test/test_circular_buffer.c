/**
 * @file test_circular_buffer.c
 * @brief Unit tests for circular buffer module
 */

#include "unity.h"
#include "circular_buffer.h"

#define BUFFER_SIZE 4

static uint8_t test_buffer[BUFFER_SIZE];
static circular_buffer_t cbuf;

void setUp(void) {
    cbuf_init(&cbuf, test_buffer, BUFFER_SIZE);
}

void tearDown(void) {}

void test_buffer_should_be_empty_after_init(void) {
    TEST_ASSERT_TRUE(cbuf_is_empty(&cbuf));
    TEST_ASSERT_FALSE(cbuf_is_full(&cbuf));
}

void test_write_and_read_single_byte(void) {
    uint8_t value = 42, out = 0;

    TEST_ASSERT_EQUAL(CBUF_OK, cbuf_write(&cbuf, value));
    TEST_ASSERT_FALSE(cbuf_is_empty(&cbuf));

    TEST_ASSERT_EQUAL(CBUF_OK, cbuf_read(&cbuf, &out));
    TEST_ASSERT_EQUAL_UINT8(value, out);
    TEST_ASSERT_TRUE(cbuf_is_empty(&cbuf));
}

void test_buffer_should_fill_and_return_full(void) {
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        TEST_ASSERT_EQUAL(CBUF_OK, cbuf_write(&cbuf, i));
    }
    TEST_ASSERT_TRUE(cbuf_is_full(&cbuf));
    TEST_ASSERT_EQUAL(CBUF_FULL, cbuf_write(&cbuf, 99)); // Overflow
}

void test_reading_from_empty_buffer_should_fail(void) {
    uint8_t out;
    TEST_ASSERT_EQUAL(CBUF_EMPTY, cbuf_read(&cbuf, &out));
}

void test_write_read_wraparound_should_work(void) {
    uint8_t value;

    // Fill and empty to create wrap-around
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        TEST_ASSERT_EQUAL(CBUF_OK, cbuf_write(&cbuf, i));
    }
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        TEST_ASSERT_EQUAL(CBUF_OK, cbuf_read(&cbuf, &value));
        TEST_ASSERT_EQUAL_UINT8(i, value);
    }

    TEST_ASSERT_TRUE(cbuf_is_empty(&cbuf));

    // Fill again
    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        TEST_ASSERT_EQUAL(CBUF_OK, cbuf_write(&cbuf, i + 10));
    }

    for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
        TEST_ASSERT_EQUAL(CBUF_OK, cbuf_read(&cbuf, &value));
        TEST_ASSERT_EQUAL_UINT8(i + 10, value);
    }
}