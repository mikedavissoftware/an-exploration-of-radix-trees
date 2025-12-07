#ifndef RADIXTREE_H
#define RADIXTREE_H

#include <memory>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>

using namespace std;

struct rt_node {
    string infix;
    int count;
    int end_count;
    // bool cap; // Initially wanted to account for capitalization of certain words but decided to exclude this from the project;
    rt_node* parent;
    map<char, rt_node*> children;
};

char convert_to_lower(char character);

vector<string> split_into_words(string to_parse);

rt_node* init_rt_node(string remainder, rt_node* parent = nullptr);

int check_overlap(string node_chars, string remainder);

void log_word(rt_node* root, string remainder);

int word_frequency(rt_node* root, string word);

#endif