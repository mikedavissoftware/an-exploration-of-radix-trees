#include "./RadixTree.h"

// It ended up being easiest to manually create an array of ASCII codes for the punctuation/others I wanted to use to split up my input string
int DELIM[] = {32, 33, 34, 40, 41, 44, 46, 47, 58, 59, 63, 91, 92, 93, 123, 124, 125};
// The above array corresponds to the following strings (apostophe used for quotes since they are not delimiters here):
// {' ', '!', '"', '(', ')', ',', '.', '/', ':', ';', '?', '[', '\', ']', '{', '|', '}'}


char convert_to_lower(char character) { // This function takes a char and converts it to its lowercase counterpart, mainly as a helper function to the function that splits the input string into individual words
    char output = character;
    if (isupper(character)) {
        output = tolower(character);
    }
    return output;
}

vector<string> split_into_words(string to_parse) {
    vector<string> words;
    string current_word = "";
    for (unsigned int i = 0; i < to_parse.length(); i++) {
        char character = to_parse[i];
        if (find(begin(DELIM), end(DELIM), character) != end(DELIM)) { // Checking if character is in delimiter string, is a space, or is a comma (special case)
            if (current_word.length() > 0) {
                words.push_back(current_word);
            }
            current_word = "";
        } else {
            current_word += convert_to_lower(character);
        }
    }
    return words;
}

rt_node* init_rt_node(string remainder, rt_node* parent) {
    rt_node* new_node = new rt_node;

    new_node->affix = remainder; // anytime a node is created, the data (affix) will be the remainder (essentially the suffix) of the word currently being logged
    new_node->count = 0;
    new_node->end_count = 0;
    new_node->parent = parent;
    map<string, rt_node*> children;

    return new_node;
}

int check_overlap(string affix, string remainder) {
    if (affix == remainder) {
        return remainder.length();
    }
    bool match = true;
    int count = 0;
    while ((match) & (count < affix.length())) {
        if (affix[count] == remainder[count]) {
            count++;
        } else {
            match = false;
        }
    }

    if (count == 0) { return -1; } // in case of no overlap error

    return count;
}

void log_word(rt_node* root, string remainder) {
    string affix = root->affix;
    root->count++; // increment count

    if (affix.length() == 0) { // if there is no affix
        root->affix = remainder; // replace empty string with remainder
        root->end_count++; // increment the end_count
        return; // exit function
    }

    if (affix == remainder) { // if the affix and remainder are equivalent
        root->end_count++; // simply increment the end_count
        return; // exit function
    }

    int overlap = check_overlap(affix, remainder);

    if (overlap == affix.length()) {
        string new_remainder = remainder.substr(overlap);
        rt_node* target = root->children[new_remainder[0]];
        if (target == nullptr) {
            root->children[new_remainder[0]] = init_rt_node(new_remainder, root);
        } else {
            log_word(target, new_remainder); // recursive call when input is shorter than overlap
        }
    }

    if (overlap < affix.length()) {
        root->affix = affix.substr(0, overlap);

        string new_affix = affix.substr(overlap);
        root->children[new_affix[0]] = init_rt_node(new_affix, root);

        string new_remainder = remainder.substr(overlap);
        rt_node* target = root->children[new_remainder[0]];
        if (target == nullptr) {
            root->children[new_remainder[0]] = init_rt_node(new_remainder, root);
        } else {
            log_word(target, new_remainder); // recursive call when input is shorter than overlap
        }
    }

    return;
}

