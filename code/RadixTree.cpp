#include "./RadixTree.h"

// It ended up being easiest to manually create an array of ASCII codes for the punctuation/others I wanted to use to split up my input string
int DELIM[] = {32, 33, 34, 40, 41, 44, 46, 47, 58, 59, 63, 91, 92, 93, 123, 124, 125};
// The above array corresponds to the following strings (apostophe used for quotes since they are not delimiters here):
// {' ', '!', '"', '(', ')', ',', '.', '/', ':', ';', '?', '[', '\', ']', '{', '|', '}'}


char convert_to_lower(char character) {
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
                cout << current_word << endl;
            }
            current_word = "";
        } else {
            current_word += convert_to_lower(character);
        }
    }
    return words;
}

