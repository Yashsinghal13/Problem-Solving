class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        int connected = 0, i=0;
        int ans=0;
        vector<bool> vis(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>,
         greater<pair<int,int>>> pq;
        while(++connected < n){
            vis[i] = true;
            for(int j=0;j<n;j++){
                if(!vis[j]) 
                    pq.push({(abs(nums[j][0] - nums[i][0]) + 
                    abs(nums[i][1] - nums[j][1])), j});
            }

            while(vis[pq.top().second]) pq.pop();
            ans=ans+=pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};