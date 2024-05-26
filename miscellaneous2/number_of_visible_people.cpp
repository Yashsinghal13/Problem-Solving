class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {

        int size = h.size();
        vector<int> ans(size, 0);
        stack<int> st;
        st.push(h[size-1]);

        for(int i=size-2; i>=0; i--){
            int count = 0;
            while(!st.empty() && h[i] > st.top()){
                st.pop();
                count++;
            }
            if(!st.empty()){
                num++;
            }
            ans[i] = count;
            st.push(h[i]);
        }
        return ans;
    }
};