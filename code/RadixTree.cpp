#include "./RadixTree.h"

vector<string> split_into_words(string to_parse) {
    vector<string> words;
    string current_word;

    for (int i = 0; i < to_parse.length(); i++) {
        cout << to_parse[i] << endl;
        if (DELIM.find(to_parse[i])) {

            if (current_word.length() > 0) {
                words.push_back(current_word);
                cout << current_word << endl;
            }
            current_word = "";
        } else {
            current_word += to_parse[i];
        }
    }

    return words;
}