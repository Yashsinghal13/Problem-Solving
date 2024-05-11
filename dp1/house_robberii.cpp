class Solution {
public:
    //Recursion+Memoization
    int maxRobCost(vector<int>&nums,int index,int size,vector<int> &dp)
    {
        if(index>=size) return 0;
        if(dp[index]!=-1) return dp[index];
        int option1=nums[index]+maxRobCost(nums,index+2,size,dp);
        int option2=0+maxRobCost(nums,index+1,size,dp);
        dp[index]=max(option1,option2);
        return dp[index];
    }
    int maxRobCostTabulation(vector<int> & nums)
    {
        //for 1 case 
        int size=nums.size()-1;
        vector<int> dp1(size,-1);
        dp1[size-1]=nums[size-1];
        for(int i=size-2;i>=0;i--)
        {
            int temp=0;
            if(i+2<size)
            {
                temp=dp1[i+2];
            }
            dp1[i]=max(dp1[i+1],nums[i]+temp);
        }
        size=nums.size();
        vector<int> dp2(size,-1);
        dp2[size-1]=nums[size-1];
        for(int i=size-2;i>=1;i--)
        {
            int temp=0;
            if(i+2<size)
            {
                temp=dp2[i+2];
            }
            dp2[i]=max(dp2[i+1],nums[i]+temp);
        }
        return max(dp1[0],dp2[1]);
    }
    int robUsingSpaceOptimisation(vector<int> &nums)
    {
        int size=nums.size();
        int next1=nums[size-2];
        int prev1=size-3>=0?max(nums[size-3],next1):next1;
        for(int i=size-4;i>=0;i--)
        {
            int temp=max(prev1,nums[i]+next1);
            next1=prev1;
            prev1=temp;
        }
        int next2=nums[size-1];
        int prev2=size-2>0?max(nums[size-2],next2):next2;
        for(int i=size-3;i>=1;i--)
        {
            int temp=max(prev2,nums[i]+next2);
            next2=prev2;
            prev2=temp;
        }
        return max(prev1,prev2);

    }
    int rob(vector<int>& nums) {
        
        // int way1=nums[0]+maxRobCost(nums,2,size-1,dp1);
        // vector<int> dp2(size,-1);
        // int way2=maxRobCost(nums,1,size,dp2);
        // return max(way1,way2);


        if(nums.size()==1) return nums[0];
        // return maxRobCostTabulation(nums);

        return robUsingSpaceOptimisation(nums);
    }
};s