class Solution {
public:
    int xor_arr(vector <int> & nums){
        int mx = 0;
        //Max Value
        int mask = 0;
        set <int> se;
        
        for(int bit=30;bit >=0;--bit){
            mask |= (1 << bit);
            for(int i=0;i<nums.size();++i){
                se.insert(nums[i] & mask);
            }
            int newMax = mx | (1 << bit);
            for(auto prefix : se){
                
               if(se.count(newMax ^ prefix)){
                    mx = newMax;
                    break;
                }
            }
            se.clear();
        }
        return mx;
    }
    int findMaximumXOR(vector<int>& nums) {
        return xor_arr(nums);
    }
};