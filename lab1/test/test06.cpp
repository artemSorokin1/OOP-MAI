#include <gtest/gtest.h>
#include "../src/vowel_deleter.h"

TEST(test_01, basic_test_set) {
    ASSERT_EQ(vowel_deleter_v1("Loser"), "Lsr");
}

TEST(test_02, basic_test_set) {
    ASSERT_EQ(vowel_deleter_v1("You are stupid!!!"), " r stpd!!!");
}

TEST(test_03, basic_test_set) {
    ASSERT_EQ(vowel_deleter_v1("GAY"), "G");
}

TEST(test_04, basic_test_set) {
    ASSERT_EQ(vowel_deleter_v1("thank u"), "thnk ");
}

TEST(test_05, basic_test_set) {
    ASSERT_EQ(vowel_deleter_v1("This website is for losers LOL!"), "Ths wbst s fr lsrs LL!");
}

TEST(test_06, basic_test_set) {
    ASSERT_EQ(vowel_deleter_v1("AAAAAAaaaaaaaAAAA"), "");
}

TEST(test_07, basic_test_set) {
    ASSERT_EQ(vowel_deleter_v1("Only TEST&"), "nl TST&");
}
