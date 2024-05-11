class Solution {
public:
    //Recursion+Memoization
    int solve(vector<int>&nums,int index,vector<int> &dp)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index]!=INT_MIN) return dp[index];
        int option1=nums[index]+solve(nums,index+2,dp);
        int option2=0+solve(nums,index+1,dp);
        dp[index]=max(option1,option2);
        return dp[index];
    }
    //Tabulation Method
    int robTabulation(vector<int>&nums)
    {
        vector<int> dp(nums.size(),INT_MIN);
        dp[nums.size()-1]=nums[nums.size()-1];
        dp[nums.size()-2]=max(nums[nums.size()-2],nums[nums.size()-1]);
        for(int i=nums.size()-3;i>=0;i--)
        {
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
    //Space Optimisation+Tabulation
    int robSpaceOptimisation(vector<int>&nums)
    {
        vector<int> dp(nums.size(),INT_MIN);
        int curr=nums[nums.size()-1];
        int prev=max(nums[nums.size()-2],nums[nums.size()-1]);
        for(int i=nums.size()-3;i>=0;i--)
        {
            int temp=max(prev,nums[i]+curr);
            curr=prev;
            prev=temp;
        }
        return prev;
    }
     
    int rob(vector<int>& nums) {
        // vector<int>dp(nums.size(),INT_MIN); 
        // int ans=solve(nums,0,dp);
         //return ans;

         if(nums.size()==1) return nums[0];
        //return robTabulation(nums);

        return robSpaceOptimisation(nums);
       
        
    }
};