#include "B/lib.h"
#include "A/index.h"
#include "gtest/gtest.h"

TEST(tests, A) {
    EXPECT_NO_THROW(corr_A());
}

TEST(tests, B) {
    EXPECT_NO_THROW(corr_B());
}

