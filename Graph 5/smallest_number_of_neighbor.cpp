class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = INT_MAX;
        vector<pair<int, int>> graph[n];
        for(auto i : edges){
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }
        int devesh;
        for(int i=0; i<n; i++){
            int source = i;
            vector<int> dis(n, INT_MAX);
            vector<int> vis(n, 0);
            set<pair<int, int>> st;
            dis[source] = 0;
            st.insert({0, source});
            while(st.size()){
                auto node = st.begin();
                int node_wt = node->first;
                int node_ = node->second;
                st.erase(node);
                if(vis[node_]) continue;
                vis[node_] = 1;
                for(auto child : graph[node_]){
                    int child_ = child.first;
                    int child_wt = child.second;
                    if(dis[child_] > dis[node_] + child_wt){
                        dis[child_] = dis[node_] + child_wt;
                        st.insert({dis[child_], child_});
                    }
                }
            }
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(j == source) continue;
                if(dis[j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt < ans){
                devesh = source;
                ans = cnt;
            }
            else if(cnt == ans){
                devesh = source;
            }    
        }
        return devesh;
    }
};