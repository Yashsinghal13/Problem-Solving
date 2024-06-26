class Solution {
public:
    int ans=INT_MAX;
    vector<int>vec;
    bool dfs(int i, int p, vector<int>&v, vector<int>adj[], int n){
        v[i]=1;
        cout<<i<<endl;
        for(auto it: adj[i]){
            if(!v[it]){
                if(dfs(it, i, v, adj, n)){return true;}
            }
            else if(it!=p){
                return true;
            }
        }
        return false;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int chk=1;
        vector<int>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>v(n, 0), v1;
        for(int i=0; i<n; i++){
            if(!v[i]){
                if(dfs(i, -1, v, adj, n)){
                    chk=-1;
                    v1.push_back(i);
                }
            }
        }
        if(chk==1){return -1;}
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, 1e9), par(n, -1);
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int child : adj[x]) {
                    if (dist[child] == (int)(1e9)) {
                        dist[child] = 1 + dist[x];
                        par[child] = x;
                        q.push(child);
                    }
                    else if (par[x] != child and par[child] != x)
                        ans = min(ans, dist[x] + dist[child] + 1);
                }
            }
        }
        if(ans==INT_MAX){return -1;}
        return ans;
    }
};