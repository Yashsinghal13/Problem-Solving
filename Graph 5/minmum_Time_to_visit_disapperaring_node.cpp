class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> time(n, INT_MAX);
        time[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [curr, u] = pq.top();
            pq.pop();

            if (curr > time[u]) 
                continue;

            for (auto& [v, w] : adj[u]) {
                int next = curr + w;
                if (next < time[v] && next < disappear[v]) {
                    time[v] = next;
                    pq.push({next, v});
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            if (time[i] < disappear[i]) {
                ans[i] = time[i];
            }
        }

        return ans;
    }
};