#include <gtest/gtest.h>
#include "../src/time_refactor.h"


TEST(test_01, basic_test_set) {
    ASSERT_EQ(time_refactor(12, 15, "am"), "12:15");
}

TEST(test_02, basic_test_set) {
    ASSERT_EQ(time_refactor(12, 15, "pm"), "00:15");
}

TEST(test_03, basic_test_set) {
    ASSERT_EQ(time_refactor(13, 00, "pm"), "Wrong data!");
}

TEST(test_04, basic_test_set) {
    ASSERT_EQ(time_refactor(12, 00, "pm"), "00:00");
}

TEST(test_05, basic_test_set) {
    ASSERT_EQ(time_refactor(00, 15, "pm"), "Wrong data!");
}

TEST(test_06, basic_test_set) {
    ASSERT_EQ(time_refactor(-100, 15, "pm"), "Wrong data!");
}

TEST(test_07, basic_test_set) {
    ASSERT_EQ(time_refactor(13, 15, "am"), "Wrong data!");
}

TEST(test_08, basic_test_set) {
    ASSERT_EQ(time_refactor(8, 30, "pm"), "20:30");
}

TEST(test_09, basic_test_set) {
    ASSERT_EQ(time_refactor(8, 30, "am"), "08:30");
}

TEST(test_10, basic_test_set) {
    ASSERT_EQ(time_refactor(1, 60, "am"), "Wrong data!");
}

TEST(test_11, basic_test_set) {
    ASSERT_EQ(time_refactor(1, 60, "pm"), "Wrong data!");
}

TEST(test_12, basic_test_set) {
    ASSERT_EQ(time_refactor(8, 59, "am"), "08:59");
}

TEST(test_13, basic_test_set) {
    ASSERT_EQ(time_refactor(8, 40, "mm"), "Wrong data!");
}

TEST(test_14, basic_test_set) {
    ASSERT_EQ(time_refactor(10, 40, "am"), "10:40");
}

TEST(test_15, basic_test_set) {
    ASSERT_EQ(time_refactor(10, 40, "pm"), "22:40");
}

