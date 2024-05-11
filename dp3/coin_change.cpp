class Solution {
public:
    //Recursion
    int numberOfCoin(vector<int>& coins,int amount,int index)
    {
        if(amount==0) return 0;
        if(index>=coins.size() && amount!=0) return INT_MAX;
        if(amount<0) return INT_MAX;
        int ans=INT_MAX;
        int option1=numberOfCoin(coins,amount-coins[index],index);
        if(option1!=INT_MAX)
        {
            ans=1+option1;
        }
        int option2=numberOfCoin(coins,amount,index+1);
        ans=min(ans,option2);
        return ans;
    }

    //Recursion+Memoization
    int solveUsingMemo(vector<int> &coins,int amount,int index,vector<vector<int>>&dp)
    {
        if(index>=coins.size() && amount!=0) return INT_MAX;
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount][index]!=-1) return dp[amount][index];
        int ans=solveUsingMemo(coins,amount,index+1,dp);
        int option1=solveUsingMemo(coins,amount-coins[index],index,dp);
        if(option1!=INT_MAX){
            option1=1+option1;
            ans=min(ans,option1);
        }
        dp[amount][index]=ans;
        return ans;
    }
    //Tabulation
    // int solveTabulation(vector<int> &nums,int amount)
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        int ans=solveUsingMemo(coins,amount,0,dp);
        //int ans=numberOfCoin(coins,amount,0);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};