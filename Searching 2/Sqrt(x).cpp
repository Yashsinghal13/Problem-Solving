class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int low=1,high=x;
        int ans;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long a=mid*mid;
            if(a<=x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};