class Solution {
public:
    bool possible(vector<int> &nums,long long mid,int op)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt=cnt+(nums[i]-1)/mid;
            if(cnt>op) return 0;
        }
        return 1;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long int low=1;
        long long int high=*max_element(nums.begin(),nums.end());
        long long int ans=0;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(possible(nums,mid,maxOperations))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;

    }
};