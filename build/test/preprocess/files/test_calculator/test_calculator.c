// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "build/vendor/unity/src/unity.h"
#include "src/calculator.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_add_should_return_sum_of_two_integers(void)
{
    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((add(2, 3))), (
   ((void *)0)
   ), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((add(-1, 1))), (
   ((void *)0)
   ), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT);
    UnityAssertEqualNumber((UNITY_INT)((-7)), (UNITY_INT)((add(-3, -4))), (
   ((void *)0)
   ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);
}