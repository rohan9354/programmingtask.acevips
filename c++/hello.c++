#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string text;
    cout << "Enter a paragraph:\n";
    getline(cin, text);

    for (size_t i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);
        } else {
            text[i] = ' ';
        }
    }

    string word;
    stringstream ss(text);
    map<string, int> freq;

    while (ss >> word) {
        freq[word]++;
    }

    vector<pair<string, int>> words;
    for (auto it : freq) {
        words.push_back(it);
    }

    sort(words.begin(), words.end(), [](pair<string,int> &a, pair<string,int> &b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    cout << "\nTop 3 most frequent words:\n";
    for (int i = 0; i < 3 && i < (int)words.size(); i++) {
        cout << words[i].first << " : " << words[i].second << "\n";
    }

    return 0;
}

