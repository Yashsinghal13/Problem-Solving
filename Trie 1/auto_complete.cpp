#include <iostream>
#include <string>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};
struct TrieNode* getTrieNode(void) {
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}
void insertWord(struct TrieNode* root, const string key) {
    struct TrieNode* pCrawl = root;

    for (int level = 0; level < key.length(); level++) {
        int index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getTrieNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}
bool isLastNode(struct TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
void getSuggestions(struct TrieNode* root, string currentPrefix) {
    if (root->isEndOfWord)
        cout << currentPrefix << endl;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            char childChar = 'a' + i;
            getSuggestions(root->children[i], currentPrefix + childChar);
        }
    }
}
int printAutoCompleteSuggestions(TrieNode* root, const string queryPrefix) {
    struct TrieNode* pCrawl = root;

    for (char c : queryPrefix) {
        int index = CHAR_TO_INDEX(c);
        
        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }
    
    if (isLastNode(pCrawl)) {
        cout << queryPrefix << endl;
        return -1;
    }

    getSuggestions(pCrawl, queryPrefix);
    return 1;
}