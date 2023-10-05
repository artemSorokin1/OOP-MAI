#include "gtest/gtest.h"
#include "../src/money.h"
#include "../src/MoneyBuilder.h"

// конструктор с параметром
TEST(test_01, basic_test_set) {
    Money money("1000,99");
    const std::string pattern = money.getSumOfMoney();
    std::cout << pattern << '\n';
    EXPECT_EQ(pattern, "100099");
}

// конструктор без параметров
TEST(test_02, basic_test_set) {
    Money money;
    const std::string pattern = money.getSumOfMoney();
    std::cout << pattern << '\n';
    EXPECT_EQ(pattern, "000");
}

// конструктор копирования
TEST(test_03, basic_test_set) {
    Money money1("123");
    Money money2(money1);
    EXPECT_EQ(money1.getSumOfMoney(), money2.getSumOfMoney());
}

// оператор присваивания
TEST(test_04, basic_test_set) {
    Money money1("1000");
    Money money2("123");
    money1 = money2;
    EXPECT_EQ(money1.getSumOfMoney(), money2.getSumOfMoney());
}


// больше
TEST(test_05, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_greater = money1 > money2;
    EXPECT_EQ(is_greater, true);
}


// больше
TEST(test_06, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_greater = (money1 > money2);
    EXPECT_EQ(is_greater, false);
}


// больше
TEST(test_07, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_greater = (money1 > money2);
    EXPECT_EQ(is_greater, false);
}


// меньше
TEST(test_08, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_lesser = (money1 < money2);
    EXPECT_EQ(is_lesser, false);
}


// меньше
TEST(test_09, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_lesser = (money1 < money2);
    EXPECT_EQ(is_lesser, true);
}


// меньше
TEST(test_10, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '0', '0'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_lesser = (money1 < money2);
    EXPECT_EQ(is_lesser, false);
}


// меньше-равно
TEST(test_11, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_lesser_equal = (money1 <= money2);
    EXPECT_EQ(is_lesser_equal, true);
}


// меньше-равно
TEST(test_12, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_lesser_equal = (money1 <= money2);
    EXPECT_EQ(is_lesser_equal, true);
}


// меньше-равно
TEST(test_13, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '0', '0'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_lesser_equal = (money1 <= money2);
    EXPECT_EQ(is_lesser_equal, false);
}


// больше-равно
TEST(test_14, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '0', '0'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_greater_equal = (money1 >= money2);
    EXPECT_EQ(is_greater_equal, true);
}


// больше-равно
TEST(test_15, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_greater_equal = (money1 >= money2);
    EXPECT_EQ(is_greater_equal, true);
}


// больше-равно
TEST(test_16, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_greater_equal = (money1 >= money2);
    EXPECT_EQ(is_greater_equal, false);
}


// равно
TEST(test_17, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_equal = (money1 == money2);
    EXPECT_EQ(is_equal, false);
}


// равно
TEST(test_18, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_equal = (money1 == money2);
    EXPECT_EQ(is_equal, true);
}


// неравно
TEST(test_19, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_equal = (money1 != money2);
    EXPECT_EQ(is_equal, true);
}


// неравно
TEST(test_20, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    bool is_equal = (money1 != money2);
    EXPECT_EQ(is_equal, false);
}


// плюс
TEST(test_21, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    Money money3 = money1 + money2;
    EXPECT_EQ(money3.getSumOfMoney(), "246");
}


// плюс
TEST(test_22, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'1', '2', '3'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    Money money3 = money1 + money2;
    EXPECT_EQ(money3.getSumOfMoney(), "1123");
}


// плюс
TEST(test_23, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'2', '0', '0', '0', '0', '0', '5', '0', '0', '0', '0', '0', '0', '0'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    Money money3 = money1 + money2;
    EXPECT_EQ(money3.getSumOfMoney(), "30000070000000");
}


// плюс
TEST(test_24, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1'};
    std::vector<unsigned char> sum_of_money2 = {'9', '9', '9'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    Money money3 = money1 + money2;
    EXPECT_EQ(money3.getSumOfMoney(), "1000");
}


// минус
TEST(test_25, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '0', '0', '0'};
    std::vector<unsigned char> sum_of_money2 = {'9', '9', '9'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    Money money3 = money1 - money2;
    EXPECT_EQ(money3.getSumOfMoney(), "1");
}


// минус
TEST(test_26, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'9', '9', '9'};
    std::vector<unsigned char> sum_of_money2 = {'1', '1', '1'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    Money money3 = money1 - money2;
    EXPECT_EQ(money3.getSumOfMoney(), "888");
}


// минус
TEST(test_27, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'4', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'2', '0'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    Money money3 = money2 - money1;
    EXPECT_EQ(money3.getSumOfMoney(), "-403");
}


// минус
TEST(test_28, basic_test_set) {
    std::vector<unsigned char> sum_of_money1 = {'1', '2', '3'};
    std::vector<unsigned char> sum_of_money2 = {'5', '6', '7'};
    Money money1 = MoneyBuilder().setArray(sum_of_money1).build();
    Money money2 = MoneyBuilder().setArray(sum_of_money2).build();
    Money money3 = money1 - money2;
    EXPECT_EQ(money3.getSumOfMoney(), "-444");
}


// список инициализации
TEST(test_29, basic_test_set) {
    Money money = {'1', '2', '3'};
    EXPECT_EQ(money.getSumOfMoney(), "123");
}


// список инициализации
TEST(test_30, basic_test_set) {
    Money money = {};
    EXPECT_EQ(money.getSumOfMoney(), "000");
}


// список инициализации
TEST(test_31, basic_test_set) {
    Money money{'2', '0', '1'};
    EXPECT_EQ(money.getSumOfMoney(), "201");
}





