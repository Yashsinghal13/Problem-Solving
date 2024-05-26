class Solution {
private:
    int dp[55][55];
    vector<vector<int>> g, m;
public:
    int solve(int x, int y){
        if(x >= g.size() - 1) return g[x][y];
        int &ret = dp[x][y];
        if(ret != -1) return ret;
        ret = INT_MAX / 2;
        for(int i = 0; i < m[x].size(); i++){
            ret = min(ret, g[x][y] + m[g[x][y]][i] + solve(x + 1, i));
        }
        return ret;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        g = grid, m = moveCost;
        memset(dp, -1, sizeof dp);
        int ans = INT_MAX;
        for(int i = 0; i < g[0].size(); i++){
            ans = min(ans, solve(0, i));
        }
        return ans;
    }
};