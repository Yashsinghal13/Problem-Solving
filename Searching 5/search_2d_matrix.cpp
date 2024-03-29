class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix[0].size()-1,mid,i=0;
        while(i<matrix.size())
        {
            if(matrix[i][high]<target)
            {
                i++;
            }
            else
            {
                if(matrix[i][low]>target)
                {
                    return false;
                }
                else
                {
                    low=0;
                    high=matrix[0].size()-1;
                    while(low<=high)
                    {
                        mid=(low+high)/2;
                        if(matrix[i][mid]==target)
                        {
                            return true;
                        }
                        else if(matrix[i][mid]>target)
                        {
                            high=mid-1;
                        }
                        else
                        {
                            low=mid+1;
                        }
                    }
                }
            }
        }
        return false;
        
    }
};