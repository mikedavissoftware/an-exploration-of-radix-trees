#ifndef RADIXTREE_H__
#define RADIXTREE_H__

#include <memory>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string DELIM = " .,;!?";

struct rt_node {
    string prefix;
    int end_count;
    bool cap;
    map<string, rt_node> node_list;
};

vector<string> split_into_words(string to_parse);

#endif RADIXTREE_H__