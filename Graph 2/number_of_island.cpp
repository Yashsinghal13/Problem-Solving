class Solution {
public:
     int calculateArea(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&visited,int m,int n)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return 0;
        }
        int L=0,R=0,U=0,D=0;
        visited[i][j]=1;
        if(j>0 && grid[i][j-1]=='1' && visited[i][j-1]==0)
        {
            L=1+calculateArea(grid,i,j-1,visited,m,n);
        }
        if(j<n-1 && grid[i][j+1]=='1' && visited[i][j+1]==0)
        {
            R=1+calculateArea(grid,i,j+1,visited,m,n);
        }
        if(i>0 && grid[i-1][j]=='1' && visited[i-1][j]==0)
        {
            U=1+calculateArea(grid,i-1,j,visited,m,n);
        }
        if(i<m-1 && grid[i+1][j]=='1' && visited[i+1][j]==0)
        {
            D=1+calculateArea(grid,i+1,j,visited,m,n);
        }
        return L+R+U+D;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int maxArea=0,count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    count++;
                    int area=1+calculateArea(grid,i,j,visited,m,n);
                }
            }
        }
        return count;
    }
};