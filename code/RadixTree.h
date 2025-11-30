#include <memory>
#include <string>
#include <map>

using namespace std;



struct rt_node {
    string next_char;
    int end_count;
    bool cap;
    map<char, rt_node> node_list;
};

