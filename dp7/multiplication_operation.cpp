class Solution {
public:
    int t(int l,int r,int i,vector<int> &a,vector<int> &g,unordered_map<int,unordered_map<int,int>> &dp)
    {
        if(i>=g.size()) return 0;
        if(dp[l].count(r)) return dp[l][r];

        int x=g[i]*a[l]+t(l+1,r,i+1,a,g,dp);
        int y=g[i]*a[r]+t(l,r-1,i+1,a,g,dp);

        return dp[l][r]=max(x,y);
    } 
    int maximumScore(vector<int>& a, vector<int>& g) {
        int n=a.size(),m=g.size();
        unordered_map<int,unordered_map<int,int>> dp;
        return t(0,n-1,0,a,g,dp);
    }
};