#include <gtest/gtest.h>
#include "../src/vowel_deleter.h"


TEST(test_01, basic_test_set) {
    ASSERT_EQ(vowel_deleter("Loser"), "Lsr");
}

TEST(test_02, basic_test_set) {
    ASSERT_EQ(vowel_deleter("You are stupid!!!"), " r stpd!!!");
}

TEST(test_03, basic_test_set) {
    ASSERT_EQ(vowel_deleter("GAAAA"), "G");
}

TEST(test_04, basic_test_set) {
    ASSERT_EQ(vowel_deleter("thank u"), "thnk ");
}

TEST(test_05, basic_test_set) {
    ASSERT_EQ(vowel_deleter("This website is for losers LOL!"), "Ths wbst s fr lsrs LL!");
}

TEST(test_06, basic_test_set) {
    ASSERT_EQ(vowel_deleter("AAAAAAaaaaaaaAAAA"), "");
}

TEST(test_07, basic_test_set) {
    ASSERT_EQ(vowel_deleter("Only TEST&"), "nl TST&");
}

TEST(test_08, basic_test_set) {
    ASSERT_EQ(vowel_deleter("123"), "123");
}

TEST(test_09, basic_test_set) {
    ASSERT_EQ(vowel_deleter("Hello, World!"), "Hll, Wrld!");
}

TEST(test_10, basic_test_set) {
    ASSERT_EQ(vowel_deleter("come on"), "cm n");
}


