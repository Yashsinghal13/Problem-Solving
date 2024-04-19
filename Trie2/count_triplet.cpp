class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            int xorSum = 0 , start = i;
            for(int k = i; k<arr.size() ; k++){
                xorSum^=arr[k];
                if(xorSum == 0) count+=(k-i);          
            }   
        }
        return count;
        
    }
};