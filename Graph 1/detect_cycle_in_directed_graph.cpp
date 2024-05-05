#include <vector>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        vector<bool> visitedInCurrentRound(V, false);
        
        for(int i = 0; i < V; i++) {
            if(vis[i]) continue;
            if(dfs(i, adj, vis, visitedInCurrentRound)) return true;
        }
        
        return false;
    }
    
    bool dfs(int curr, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& visitedInCurrentRound) {
        vis[curr] = true;
        visitedInCurrentRound[curr] = true;
        
        for(int i : adj[curr]) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, visitedInCurrentRound)) return true;
            }
            else if(visitedInCurrentRound[i]) {
                return true;
            }
        }
        
        visitedInCurrentRound[curr] = false;
        return false;
    }
};
