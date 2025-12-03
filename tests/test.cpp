#include "../code/RadixTree.h"
#include <gtest/gtest.h>

#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const string PARSE_1 = "This is the test string of text. You know, the one that will indeed be indexed by Mike's radix tree data structure. It will certainly happen.";

TEST(test_suite, InitialTests) {
    vector<string> word_list = split_into_words(PARSE_1);
    // EXPECT_EQ(word_list[24], "certainly");
}