class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector <int>& tasks) {
        vis[node] = 2;
        for (auto it: adj[node]) {
            if (vis[it] == 0) {
                if (dfs(it, adj, vis, tasks) == true)
                    return true;
            } else if (vis[it] == 2) {
                return true;
            }
        }
        tasks.push_back(node);
        vis[node] = 1;
        return false;  
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector <int> vis(numCourses, 0);
        vector <int> adj[numCourses];
        for (int i = 0; i < n; i++) 
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector <int> tasks;    
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (dfs(i, adj, vis, tasks) == true)
                    return {};
            }
        }
        reverse(tasks.begin(), tasks.end());
        return tasks;
    }
};