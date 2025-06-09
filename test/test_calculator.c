#include "unity.h"
#include "calculator.h"

void setUp(void) {
    // Optional setup before each test
}

void tearDown(void) {
    // Optional cleanup after each test
}

/* void test_add_should_return_sum_of_two_integers(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(0, add(-1, 1));
    TEST_ASSERT_EQUAL(-7, add(-3, -4));
}
 */
void test_mul_should_return_multiplication_of_two_integers(void) {
    TEST_ASSERT_EQUAL(6, multiply(2, 3));
    TEST_ASSERT_EQUAL(-1, multiply(-1, 1));
    TEST_ASSERT_EQUAL(12, multiply(-3, -4));
}