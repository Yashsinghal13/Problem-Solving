class Solution {
public:
    //Recursion Approach
    // int solve(string &word1,string &word2,int i,int j)
    // {
    //     if(i>=word1.size())
    //     {
    //         return word2.size()-j;
    //     }
    //     if(j>=word2.size())
    //     {
    //         return word1.size()-i;
    //     }
    //     if(word1[i]==word2[j]){
    //         return solve(word1,word2,i+1,j+1);
    //     }
    //     //insert
    //     int option1=1+solve(word1,word2,i,j+1);
    //     int option2=1+solve(word1,word2,i+1,j);
    //     int option3=1+solve(word1,word2,i+1,j+1);
    //     return min(option1,min(option2,option3));
    // }
    //Recursion+Memo
    int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&cache)
    {
        if(i>=word1.size())
        {
            return word2.size()-j;
        }
        if(j>=word2.size())
        {
            return word1.size()-i;
        }
        if(cache[i][j]!=-1) return cache[i][j];
        if(word1[i]==word2[j]){
             cache[i][j]=solve(word1,word2,i+1,j+1,cache);
             return cache[i][j];
        }
        //insert
        int option1=1+solve(word1,word2,i,j+1,cache);
        int option2=1+solve(word1,word2,i+1,j,cache);
        int option3=1+solve(word1,word2,i+1,j+1,cache);
        cache[i][j]=min(option1,min(option2,option3));
        return cache[i][j];
    }
    //DP SOLUTION TABULATION
    int SolveUsingTabulation(string word1, string word2) 
    {
    int m= word1.size();
    int n = word2.size();
    vector<vector<int>> cache(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                cache[i][j] = j;
            } else if (j == 0) {
                cache[i][j] = i;
            } else if (word1[i - 1] == word2[j - 1]) {
                cache[i][j] = cache[i - 1][j - 1];
            } else {
                cache[i][j] = 1 + min(cache[i][j - 1],min(cache[i - 1][j],cache[i - 1][j - 1]));
            }
        }
    }
    return cache[m][n];
}



public:
    int minDistance(string word1, string word2) {
        // int i=0,j=0;
        // int m=word1.size();
        // int n=word2.size();
        // vector<vector<int>> cache(m,vector<int>(n,-1));
        // int minop=solve(word1,word2,i,j,cache);
        return SolveUsingTabulation(word1,word2);
        //return minop;
        
    }
};