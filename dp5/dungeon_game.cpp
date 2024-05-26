class Solution {
public:
int fun(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>> &dp){
    if(i>=dp.size()||j>=dp[0].size()) return 5e5;
    if(i==dp.size()-1&&j==dp[0].size()-1) {
        if(dungeon[i][j]<=0) return abs(dungeon[i][j])+1;
        else return 1;
    } 
    if(dp[i][j]!=-1) return dp[i][j];
    int up=fun(i+1,j,dungeon,dp);
    int down=fun(i,j+1,dungeon,dp);
    int minhealthreq=min(up,down)-dungeon[i][j];
    return dp[i][j]=(minhealthreq<=0)?1:minhealthreq;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
       return fun(0,0,dungeon,dp); 
    }
};