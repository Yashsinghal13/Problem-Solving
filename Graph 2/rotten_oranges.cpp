class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        int vis[n][m];

        int fresh=0;
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        
        int maxt=0;
        int rot=0;
        while(!q.empty()){
            int row= q.front().first.first;
            int col=q.front().first.second;
            int tm= q.front().second;
            maxt=max(tm,maxt);
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow= row+delRow[i];
                int ncol= col+delCol[i];
                
                if(nrow>=0&& nrow<n && ncol>=0 && ncol<m
                && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},tm+1});
                    vis[nrow][ncol]=2;
                    rot++;
                }
                
            }
        }
        if(rot!=fresh) return -1;
        return maxt;
    }
};