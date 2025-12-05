#include "../code/RadixTree.h"
#include <gtest/gtest.h>

#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const string TEST_TEXT_1 = "This is the test string of text. You know, the one that will indeed be indexed by Mike's radix tree data structure. It will certainly happen.";

const string TEST_TEXT_2 = "The th";

TEST(test_RadixTree, TestConvertToLower) {
    char upper = 'A';
    char lower = 'a';
    ASSERT_EQ(convert_to_lower(upper), lower);
}

TEST(test_RadixTree, TestWordSplitter) {
    vector<string> word_list = split_into_words(TEST_TEXT_1);
    EXPECT_EQ(word_list[24], "certainly");
    EXPECT_EQ(word_list.size(), 26);
}

TEST(test_RadixTree, TestInitNode) {
    rt_node* test_node = init_rt_node("test");

    ASSERT_TRUE(test_node);
    ASSERT_EQ(test_node->affix, "test");
    ASSERT_EQ(test_node->count, 0);
    ASSERT_EQ(test_node->end_count, 0);
    ASSERT_EQ(test_node->parent, nullptr);
    ASSERT_EQ(test_node->children.size(), 0); // check that map exists and is empty

    rt_node* test_node_w_parent = init_rt_node("test2", test_node);
    ASSERT_EQ(test_node_w_parent->parent, test_node);
}

TEST(test_RadixTree, TestCheckOverlap) {
    string a = "a";
    string ab = "ab";
    string b = "b";

    ASSERT_EQ(check_overlap(a, a), a.length());  // check when equivalent single-character strings have full-length overlap
    ASSERT_EQ(check_overlap(a, ab), a.length()); // check when remainder stretches beyond affix
    ASSERT_EQ(check_overlap(ab, a), 1); // check when remainder only contains part of affix
    ASSERT_EQ(check_overlap(ab, ab), 2); // check when equivalent double-character strings have full-length overlap
    ASSERT_EQ(check_overlap(a, b), -1); // check when there is no overlap (error)
}

TEST(test_RadixTree, TestLogWords) {
    vector<string> words = split_into_words(TEST_TEXT_2);
    rt_node* rtn = init_rt_node("");
    for (auto word : words) {
        log_word(rtn, word);
    }
    ASSERT_EQ(rtn->affix, "th");
}

// TEST(test_RadixTree, TestName) {
    
// }

// TEST(test_RadixTree, TestName) {
    
// }

// TEST(test_RadixTree, TestName) {
    
// }

// TEST(test_RadixTree, TestName) {
    
// }