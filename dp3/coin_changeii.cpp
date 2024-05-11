class Solution {
public:
    int numberofways(int amount,vector<int> &coins,int index,vector<vector<int>>&cache)
    {
        if(amount==0) return 1;
        if(index>=coins.size() || amount<0) return 0;
        if(cache[amount][index]!=-1) return cache[amount][index];
        int a=numberofways(amount,coins,index+1,cache);
        int b=numberofways(amount-coins[index],coins,index,cache);
        cache[amount][index]=a+b;
        return a+b;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>cache(amount+1,vector<int>(coins.size(),-1));
        return numberofways(amount,coins,0,cache);
    }
};
