class Solution {
public:
    long long solve(vector<vector<int>>&questions,int index,vector<long long>&cache)
    {
        if(index>=questions.size()) return 0;
        if(cache[index]!=-1) return cache[index];
        long long option1=questions[index][0]+solve(questions,index+questions[index][1]+1,cache);
        long long option2=solve(questions,index+1,cache);
        cache[index]=max(option1,option2);
        return cache[index];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> cache(questions.size(),-1);
        return solve(questions,0,cache);
    }
};