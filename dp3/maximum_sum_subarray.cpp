class Solution {
public:
    int maxsubarrayhelper(vector<int> &nums,int start,int end)
    {
        if(start==end) return nums[start];
        int mid=start+(end-start)/2;
        int maxsumleft=maxsubarrayhelper(nums,start,mid);
        int maxsumright=maxsubarrayhelper(nums,mid+1,end);
         int maxleftbordersum=INT_MIN,maxrightbordersum=INT_MIN;       
        int leftsum=0,rightsum=0;
        for(int i=mid;i>=start;i--)
        {
            leftsum=leftsum+nums[i];
            if(leftsum>maxleftbordersum)
            {
                maxleftbordersum=leftsum;
            }
        }
        for(int i=mid+1;i<=end;i++)
        {
            rightsum=rightsum+nums[i];
            if(rightsum>maxrightbordersum)
            {
                maxrightbordersum=rightsum;
            }
        }
        int crosssum= maxleftbordersum+maxrightbordersum;
        return max(maxsumleft,max(maxsumright,crosssum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxsubarrayhelper(nums,0,nums.size()-1);
    }
};