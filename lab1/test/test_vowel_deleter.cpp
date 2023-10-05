#include <gtest/gtest.h>
#include "../src/vowel_deleter.h"


TEST(test_01, basic_test_set) {
    std::string text = "Loser";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "Lsr");
}


TEST(test_02, basic_test_set) {
    std::string text = "You are stupid!!!";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, " r stpd!!!");
}


TEST(test_03, basic_test_set) {
    std::string text = "GAAAA";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "G");
}


TEST(test_04, basic_test_set) {
    std::string text = "thank u";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "thnk ");
}


TEST(test_05, basic_test_set) {
    std::string text = "This website is for losers LOL!";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "Ths wbst s fr lsrs LL!");
}


TEST(test_06, basic_test_set) {
    std::string text = "AAAAAAaaaaaaaAAAA";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "");
}


TEST(test_07, basic_test_set) {
    std::string text = "Only TEST&";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "nl TST&");
}


TEST(test_08, basic_test_set) {
    std::string text = "123";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "123");
}


TEST(test_09, basic_test_set) {
    std::string text = "Hello, World!";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "Hll, Wrld!");
}


TEST(test_10, basic_test_set) {
    std::string text = "come on";
    std::string pattern = vowel_deleter(text);
    EXPECT_EQ(pattern, "cm n");
}


