//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST_F(LeapTestCase, IS_LEAP_SIMPLE) {
    ASSERT_ANY_THROW(IsLeap(0));
    ASSERT_TRUE(IsLeap(400));
    ASSERT_FALSE(IsLeap(100));
    ASSERT_TRUE(IsLeap(4));
    ASSERT_FALSE(IsLeap(1));
}

TEST_F(LeapTestCase, GET_MONTH_DAYS) {
    ASSERT_EQ(GetMonthDays(400, 2), 29);
    ASSERT_EQ(GetMonthDays(1, 2), 28);
    ASSERT_ANY_THROW(GetMonthDays(0, 13));
    ASSERT_EQ(GetMonthDays(10, 4), 30);
    ASSERT_EQ(GetMonthDays(5, 5), 31);
}