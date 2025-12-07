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
    if (current_word.length() > 0) { // Had to come back later to add this, since I didn't account for an input string that didn't end in a delimiter character, and therefore wouldn't be added to the word list
        words.push_back(current_word);
    }
    return words;
}

rt_node* init_rt_node(string remainder, rt_node* parent) {
    rt_node* new_node = new rt_node;

    new_node->infix = remainder; // anytime a node is created, the data (infix) will be the remainder (essentially the suffix) of the word currently being logged
    new_node->count = 0;
    new_node->end_count = 0;
    new_node->parent = parent;
    map<string, rt_node*> children;

    return new_node;
}

int check_overlap(string infix, string remainder) {
    if (infix == remainder) {
        return remainder.length();
    }
    bool match = true;
    unsigned int count = 0;
    while ((match) & (count < infix.length())) {
        if (infix[count] == remainder[count]) {
            count++;
        } else {
            match = false;
        }
    }

    if (count == 0) { return -1; } // in case of no overlap error

    return count;
}

void log_word(rt_node* root, string remainder) {
    // cout << "log word loop with remainder " << remainder << endl; // print statement to record another recursion
    string infix = root->infix;
    char first_char = remainder[0];
    root->count++; // increment count

    if (root->parent == nullptr) {
        // cout << "root node loop" << endl; // print statement to indicate which loop
        if (root->children.count(first_char) == 0) {
            rt_node* new_node = init_rt_node("", root);
            root->children[first_char] = new_node;
            log_word(root->children[first_char], remainder);
        } else {
            log_word(root->children[first_char], remainder);
        }
        return; // FORGOT TO HAVE THIS HERE INITIALLY; the recursion means anytime the logging inevitably returns to the root node, it needs to exit the function
    }

    if (infix.length() == 0) { // if there is no infix
        // cout << "no infix loop" << endl; // print statement to indicate which loop
        root->infix = remainder; // replace empty string with remainder
        root->end_count++; // increment the end_count
        return; // exit function
    }

    if (infix == remainder) { // if the infix and remainder are equivalent
        // cout << "infix == remainder loop" << endl; // print statement to indicate which loop
        root->end_count++; // simply increment the end_count
        return; // exit function
    }

    unsigned int overlap = check_overlap(infix, remainder);

    if (overlap == infix.length()) {
        // cout << "full overlap loop" << endl; // print statement to indicate which loop
        string new_remainder = remainder.substr(overlap);
        rt_node* target = root->children[new_remainder[0]];
        if (target == nullptr) {
            root->children[new_remainder[0]] = init_rt_node(new_remainder, root);
        } else {
            log_word(target, new_remainder); // recursive call when input is shorter than overlap
        }
    }

    if (overlap < infix.length()) {
        // cout << "partial overlap loop" << endl; // print statement to indicate which loop

        root->infix = infix.substr(0, overlap);

        string child_infix = infix.substr(overlap);
        root->children[child_infix[0]] = init_rt_node(child_infix, root);

        string new_remainder = remainder.substr(overlap);
        root->children[new_remainder[0]] = init_rt_node(new_remainder, root);
    }

    return;
}

int word_frequency(rt_node* root, string word) {

    if (root->infix == word) { // base case
        return root->end_count;
    }

    int overlap = check_overlap(root->infix, word);
    string remainder = word.substr(overlap);

    if (root->children.find(remainder[0]) != root->children.end()) {
        return word_frequency(root->children[remainder[0]], remainder);
    } else {
        return 0;
    }

    return 0;
}