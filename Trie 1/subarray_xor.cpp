#include <iostream>
#include <vector>
using namespace std;

// Trie node structure
//Good Question and important Question
struct TrieNode {
    TrieNode* child[2]; // For binary XOR values (0 or 1)
    int count; // Number of elements below this node in the trie

    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
        count = 0;
    }
};

// Trie operations
void insertTrie(TrieNode* root, int num) {
    TrieNode* curr = root;
    for (int i = 20; i >= 0; --i) { // We consider bits up to 20 because 2^20 > 10^6
        int bit = (num >> i) & 1;
        if (!curr->child[bit])
            curr->child[bit] = new TrieNode();
        curr = curr->child[bit];
        curr->count++;
    }
}

int queryTrie(TrieNode* root, int num, int k) {
    TrieNode* curr = root;
    int result = 0;
    for (int i = 20; i >= 0 && curr; --i) { // Traverse through bits
        int bit_num = (num >> i) & 1;
        int bit_k = (k >> i) & 1;
        
        if (bit_k) { // If current bit of K is 1
            if (curr->child[bit_num]) // Include all such elements
                result += curr->child[bit_num]->count;
            curr = curr->child[1 - bit_num]; // Move to the opposite child
        } else { // If current bit of K is 0
            curr = curr->child[bit_num]; // Move to the same child
        }
    }
    return result;
}

int countSubarraysWithXorLessThanK(const vector<int>& arr, int n, int k) {
    TrieNode* root = new TrieNode();
    int xor_val = 0;
    insertTrie(root, 0); 
    int count_subarrays = 0;

    for (int j = 0; j < n; ++j) {
        xor_val ^= arr[j];
        count_subarrays += queryTrie(root, xor_val, k);
        insertTrie(root, xor_val);
    }

    return count_subarrays;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int result = countSubarraysWithXorLessThanK(arr, n, k);
        cout << result << endl;
    }

    return 0;
}
