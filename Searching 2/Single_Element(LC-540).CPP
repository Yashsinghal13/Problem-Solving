class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(mid+1<nums.size() && nums[mid+1]!=nums[mid] && mid-1>=0 &&nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
            else if(mid%2==1 && nums[mid-1]==nums[mid])
            {
                low=mid+1;
            }
            else if(mid%2==0 && nums[mid+1]==nums[mid])
            {
                low=mid+2;
            }
            else
            {
                high=mid;
            }
        }
        return nums[low];
    }   
};