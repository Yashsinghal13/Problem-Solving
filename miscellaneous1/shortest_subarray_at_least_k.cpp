class Solution {
    
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,long long>>d;
        long long sum=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>=k)
            ans=min(ans,i+1);
            while(d.size() && sum<d.back().first)
            {
                d.pop_back();
            }
            d.push_back({sum,i});
                cout<<ans<<endl;
                while(d.size() && sum-d.front().first>=k)
                {
                    if(ans>i-d.front().second)
                    ans=i-d.front().second;
                    d.pop_front();
                }

        }
        if(ans==INT_MAX)
        ans=-1;
        return ans;
    }
};