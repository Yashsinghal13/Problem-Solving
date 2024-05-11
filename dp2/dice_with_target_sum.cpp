class Solution {
public:
    public: int MOD=1e9+7;
    int helper(int n,int k,int target,vector<vector<int>> &cache)
    {
        if(target<0) return 0;
        if(target==0 && n==0) return 1;
        if(n==0 && target!=0) return 0;
        if(cache[n][target]!=-1) return cache[n][target];
        int count=0;
        for(int i=1;i<=k;i++)
        {
            count=(count+helper(n-1,k,target-i,cache))%MOD;
        }
        cache[n][target]=count;
        return count;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>cache(n+1,vector<int>(target+1,-1));
        int count=helper(n,k,target,cache);
        return count;
        
    }
};