class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency List
        vector<pair<int,int>> adj[n];

        for(auto i: flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}}); 

        while(!q.empty()){
            auto ft=q.front();
            q.pop();

            int stops=ft.first, source=ft.second.first, distance=ft.second.second;

            for(auto j: adj[source]){
                int node=j.first;
                int cost=j.second;


                if((distance+cost) < dist[node] && stops <= k){
                    dist[node]=cost + distance;
                    q.push({stops+1,{node,dist[node]}});
                }
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
        
    }
};