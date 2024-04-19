class Solution {
public:

struct Trie {
    Trie * child[2]{};
    int cnt = 0;
};
    void addNode(Trie * root, int t) {
        for(int i = 31; i >= 0; i--) {
            int v = (t >> i)&1;
            if(root->child[v] == nullptr) root->child[v] = new Trie();
            root = root->child[v];
            root->cnt += 1;
        }
    }

    int countPairs(vector<int>& A, int low, int high) {
        Trie * root = new Trie();

        function<int(Trie *, int, int)> dfs = [&](Trie * n, int idx, int cur)->int {
            if(n == nullptr) return 0;
            if(idx == 0) return (cur >= low && cur <= high) ? n->cnt : 0;

            int l = (low >> idx) << idx, h = (high >> idx) << idx, v = (cur >> idx) << idx;
            return v > l && v < h ? n->cnt : v < l || v > h ? 0 : dfs(n->child[0], idx-1, cur)+dfs(n->child[1], idx-1, cur ^ (1 << (idx-1)));
        };

        int res = 0;
        for(auto e : A) {
            res += dfs(root->child[0], 31, e) + dfs(root->child[1], 31, e ^ (1 << 31));
            addNode(root, e);
        }
        return res;
    }
};