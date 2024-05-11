class Solution {
public:
    int solve(string &s,int index,vector<int> &cache)
    {
        if(index>=s.size()) return 1;
        if(s[index]=='0') return 0;
        if(cache[index]!=-1) return cache[index];
        int option1=0,option2=0;
        option1=solve(s,index+1,cache);
        if(index+1<s.size() && s[index]<='2')
        {
            if((s[index]=='2' && s[index+1]<='6' )|| s[index]<'2')
            {
                option2=solve(s,index+2,cache);
            }
        }
        cache[index]=option1+option2;
        return cache[index];
    }
    int numDecodings(string s) {
        vector<int> cache(s.size(),-1);
        return solve(s,0,cache);
    }
};