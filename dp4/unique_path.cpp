class Solution {
    int numberofways(int m,int n,vector<vector<int>> &cache)
    {
        if(cache[m][n]!=-1) return cache[m][n];
        if(m==0 || n==0) {
            cache[m][n]=1 ;
            return 1;
        }
        int x=numberofways(m-1,n,cache);
        int y=numberofways(m,n-1,cache);
        cache[m][n]=x+y;
        return x+y;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>v(m,vector<int>(n,-1));
       return numberofways(m-1,n-1,v);
    }
};