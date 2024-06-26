class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

    int findNumProvinces(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        vector<int> vis(n);

        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};
