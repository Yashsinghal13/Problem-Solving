#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long ways(int target,vector<long long int>&cache)
{
    if(target==0) return 1;
    if(target<0) return 0;
    if(cache[target]!=-1) return cache[target];
    long long int ans=0;
    for(int i=1;i<=6;i++)
    {
        ans=(ans+ways(target-i,cache))%MOD;
    }
    cache[target]=ans;
    return cache[target];
}
long long solveUsingTabulation(long long int target)
{
    vector<long long> dp(target+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=target;i++)
    {
        long long sum=0;
        for(int j=1;j<=6;j++)
        {
            if((i-j)<0) break;
            sum=(sum+dp[i-j])%MOD;
        }
        dp[i]=sum%MOD;
    }
    return dp[target]; 
}
int main()
{
    long long int target;
    cin>>target;
     // vector<long long int> cache(target+1,-1);
    // cout<<ways(target,cache);
    cout<<solveUsingTabulation(target);
    return 0;
}