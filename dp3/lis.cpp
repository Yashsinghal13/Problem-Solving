class Solution {
public:
    //Recursion-->It give TLE
    // int lis(vector<int> &nums,int index,int prev_ind)
    // {
    //     if(index>=nums.size())
    //     {
    //         return 0;
    //     }
    //     int c1=0+lis(nums,index+1,prev_ind);
    //     if(prev_ind!=-1 && nums[prev_ind]<nums[index])
    //     {
    //         prev_ind=index;   
    //         int c2=1+lis(nums,index+1,prev_ind);
    //         return max(c1,c2);
    //     }
    //     else if(prev_ind==-1)
    //     {
    //         prev_ind=index;
    //         int c2=1+lis(nums,index+1,prev_ind);
    //         return max(c1,c2);
    //     }
    //     return c1;
    // }
    //Recursion+Memorization
    int lis(vector<int> &nums,int index,int prev_ind,vector<vector<int>> &cache)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(cache[index][prev_ind+1]!=-1)
        {
            return cache[index][prev_ind+1];
        }
        int c1=0+lis(nums,index+1,prev_ind,cache);
        if(prev_ind==-1 || (prev_ind!=-1 && nums[prev_ind]<nums[index]))
        { 
            int c2=1+lis(nums,index+1,index,cache);
            c1=max(c1,c2);
        }
        cache[index][prev_ind+1]=c1;
        return c1;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> cache(nums.size(),vector<int>(nums.size()+1,-1));
        int l=lis(nums,0,-1,cache);
        return l;
    }
};