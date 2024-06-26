class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();

        int dp[m][n];
        memset(dp,-1,sizeof(dp));
        dp[m-1][n-1] = grid[m-1][n-1]; //initialising last element

        for(int i=m-2;i>=0;i--)
            dp[i][n-1] = dp[i+1][n-1] + grid[i][n-1]; //initialising last column as we can only go down from here
        for(int i=n-2;i>=0;i--)
            dp[m-1][i] = dp[m-1][i+1] + grid[m-1][i]; //initialising bottom row as we can only go right from here
        
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};