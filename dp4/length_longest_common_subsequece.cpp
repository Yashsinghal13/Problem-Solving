class Solution {
public:
    int solve(vector<int>&nums,int target,int index,vector<vector<int>>&cache)
    {
        if(target==0 && index<=nums.size()) return 0;
        if(index>=nums.size()) return INT_MIN;
        if(target<0) return INT_MIN;
        if(cache[target][index]!=-1) return cache[target][index];
        int option1=solve(nums,target,index+1,cache);
        int option2=1+solve(nums,target-nums[index],index+1,cache);
        cache[target][index]=max(option1,option2);
        return cache[target][index];
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> cache(target+1,vector<int>(nums.size(),-1));
        int ans=solve(nums,target,0,cache);
        if(ans<=0) return -1;
        else return ans;

    }
};