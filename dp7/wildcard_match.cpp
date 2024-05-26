class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size(); 
        vector<vector<short>> memo(n, vector<short>(m, -1));
        return dp(s, p, n-1, m-1, memo);
    }

private:
    bool dp(string& s, string& p, int i, int j, vector<vector<short>>& memo) {
        if (i < 0) {
            while (j >= 0)
                if (p[j--] != '*') return false;
            return true;
        }
        if (j < 0) return false;
        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == p[j] || p[j] == '?') return memo[i][j] = dp(s, p, i-1, j-1, memo);
        if (p[j] == '*') return memo[i][j] = dp(s, p, i-1, j, memo) || dp(s, p, i, j-1, memo);

        return memo[i][j] = false;
    }
};