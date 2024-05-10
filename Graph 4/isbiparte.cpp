class Solution {
private:
    bool bfs(vector<vector<int>>& graph,vector<int>& color,int sv){
        queue<int> q;
        q.push(sv);
        color[sv]=0;
        while(!q.empty()){
            int t=q.front();
            int c=color[t];
            q.pop();
            for(auto x:graph[t]){
                if(color[x]==-1){
                    color[x]=!c;
                    q.push(x);
                }
                else if(color[x]==c){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(graph,color,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};