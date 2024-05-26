#include<bits/stdc++.h>
using namespace std;
//Recursion
int minCoins(vector<int>&coins,int amount,int index)
{
    if(amount==0 && index<=coins.size()) return 0;
    if(index>=coins.size()) return INT_MAX;
    if(amount<0) return INT_MAX;
    int option1=minCoins(coins,amount,index+1);
    int option2=minCoins(coins,amount-coins[index],index);
    if(option2!=INT_MAX)
    {
        option2=1+option2;
    }
    return min(option1,option2);
}
//Recursion+Memo
int minCoins(vector<int>&coins,int amount,int index,vector<vector<int>>&cache)
{
    if(amount==0 && index<=coins.size()) return 0;
    if(index>=coins.size()) return INT_MAX;
    if(amount<0) return INT_MAX;
    if(cache[amount][index]!=-1) return cache[amount][index];
    int option1=minCoins(coins,amount,index+1,cache);
    int option2=minCoins(coins,amount-coins[index],index,cache);
    if(option2!=INT_MAX)
    {
        option2=1+option2;
    }
    cache[amount][index]=min(option1,option2);
    return cache[amount][index];
}

int main()
{
    int n,amount;
    cin>>n>>amount;
    vector<int> coins(n);
    vector<int> cache(amount+1,-1);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    int ans=minCoins(coins,amount,0,cache);
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
    
    return 0;
}