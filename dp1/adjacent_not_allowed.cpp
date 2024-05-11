class Solution{
public:
    int solve(vector<vector<int>>&mat,int col,int n,vector<int> &cache)
    {
        if(col>=n) return 0;
        if(cache[col]!=-1) return cache[col];
        int option1=solve(mat,col+1,n,cache);
        int option2=max(mat[0][col],mat[1][col])+solve(mat,col+2,n,cache);
        cache[col]=max(option1,option2);
        return cache[col];
    }
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
        vector<int> cache(N,-1);
        return solve(mat,0,N,cache);
    }
};