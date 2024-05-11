class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    int cnt = 0;
    for(int i=0; i<row.size(); i++){
        if(row[i]%2 == 1){
            row[i]--;
        }
    }
    for(int i=0; i<row.size(); i=i+2){
        if(row[i] == row[i+1]){
            continue;
        }
        else{
            for(int j=i+2; j<row.size(); j++){
                if(row[i] == row[j]){
                    swap(row[j], row[i+1]);
                    break;
                }
            }
            cnt++;
        }
    }
    return cnt;
    
};