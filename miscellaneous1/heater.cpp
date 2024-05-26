class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size();

        if(m == 1) {
            int ans = 0;
            for(int x : houses) ans = max(ans, abs(x - heaters[0]));
            return ans;
        }
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int l = 0, r = 1, i = 0, ans = 0, mid;

        while(r < m) {
            mid = (heaters[l] + heaters[r])/2;
            while(i < n && houses[i] <= mid) ans = max(ans, abs(heaters[l] - houses[i++])); 
            while(i < n && houses[i] <= heaters[r]) ans = max(ans, abs(heaters[r] - houses[i++])); 
            l++; r++;
        }

        if(houses[n - 1]  > heaters[r - 1]) ans = max(ans, houses[n - 1] - heaters[r - 1]);
        return ans;
    }
};