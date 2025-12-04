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
    string prefix;
    int end_count;
    bool cap;
    map<string, rt_node> node_list;
};

vector<string> split_into_words(string to_parse);

#endif // RADIXTREE_H