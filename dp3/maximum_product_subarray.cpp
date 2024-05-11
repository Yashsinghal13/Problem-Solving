class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxl=1;
        int maxpr=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxl=maxl*nums[i];
            ans=max(ans,maxl);
            if(maxl==0) maxl=1;
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            maxpr=maxpr*nums[i];
            ans=max(ans,maxpr);
            if(maxpr==0) maxpr=1;
        }
        return ans;
        
    }
};