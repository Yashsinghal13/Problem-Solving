class Solution {
public:
    int lcshelper(string &text1,string &text2,int index1,int index2,vector<vector<int>>&cache)
    {
        if(index1>=text1.size() || index2>=text2.size()) return 0;
        int option1=0,option2=0;
        if(cache[index1][index2]!=-1) return cache[index1][index2];
        if(text1[index1]==text2[index2])
        {
            return 1+lcshelper(text1,text2,index1+1,index2+1,cache);
        }
        else
        {
            option1=lcshelper(text1,text2,index1+1,index2,cache);
            option2=lcshelper(text1,text2,index1,index2+1,cache);
            cache[index1][index2]=max(option1,option2);
            return max(option1,option2);
        }
    }
    int solveUsingTabulation(string &text1,string &text2)
    {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=text1.length()-1;i>=0;i--)
        {
            for(int j=text2.length()-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int solvUsingSpaceOptimization(string &text,string &text2)
    {
        vector<int>next(text1.size()+1,0);
        vector<int>curr(text1.size()+1,0);
        for(int i=text1.size()-1;i>=0;i--)
        {
            for(int j=text2.size()-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    curr[i]=1+next[i+1][j+1];
                }
                else
                {
                    curr[i]=max(curr[i+1],next[j+1]);
                }
            }
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>>cache(text1.size(),vector<int>(text2.size(),-1));
        // return lcshelper(text1,text2,0,0,cache);

        return solveUsingTabulation(text1,text2);
    }
};