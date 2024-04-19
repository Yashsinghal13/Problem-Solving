#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int frequency;
    
    TrieNode() : isEndOfWord(false), frequency(0) {}
};

class AutocompleteSystem {
private:
    TrieNode* root;
    string prefix;

    void insert(const string& sentence, int times) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
        node->frequency += times;
    }

    struct Compare {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
            return (a.second > b.second) || (a.second == b.second && a.first < b.first);
        }
    };

    vector<string> search(TrieNode* node) {
        vector<pair<string, int>> results;
        if (node->isEndOfWord) {
            results.push_back({prefix, node->frequency});
        }
        for (auto& child : node->children) {
            prefix.push_back(child.first);
            vector<string> childResults = search(child.second);
            prefix.pop_back();
            results.insert(results.end(), childResults.begin(), childResults.end());
        }
        sort(results.begin(), results.end(), Compare());
        vector<string> topResults;
        for (int i = 0; i < min(3, (int)results.size()); ++i) {
            topResults.push_back(results[i].first);
        }
        return topResults;
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insert(prefix, 1);
            prefix = "";
            return {};
        }

        prefix.push_back(c);
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children.count(ch)) {
                return {};
            }
            node = node->children[ch];
        }

        return search(node);
    }
};

int main() {
    vector<string> sentences = {"i love you", "island", "ironman", "i love geeksforgeeks"};
    vector<int> times = {5, 3, 2, 2};

    AutocompleteSystem obj(sentences, times);

    vector<string> result1 = obj.input('i');
    for (const string& s : result1) {
        cout << s << " ";
    }
    cout << endl;

    vector<string> result2 = obj.input(' ');
    for (const string& s : result2) {
        cout << s << " ";
    }
    cout << endl;

    vector<string> result3 = obj.input('a');
    for (const string& s : result3) {
        cout << s << " ";
    }
    cout << endl;

    vector<string> result4 = obj.input('#'); // Save "i a"
    for (const string& s : result4) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
