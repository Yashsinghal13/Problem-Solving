class Solution {
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i]) dfs(i, adj, visited, Stack);
        }
        Stack.push(v);
    }

    void dfsTranspose(int v, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i]) dfsTranspose(i, adj, visited);
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        stack<int> Stack;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) dfs(i, adj, visited, Stack);
        }
        
        vector<vector<int>> adjTranspose(V);
        for (int i = 0; i < V; ++i) {
            for (int j : adj[i]) {
                adjTranspose[j].push_back(i);
            }
        }

        fill(visited.begin(), visited.end(), false);
        int sccCount = 0;
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();
            if (!visited[v]) {
                dfsTranspose(v, adjTranspose, visited);
                ++sccCount;
            }
        }
        return sccCount;
    }
};