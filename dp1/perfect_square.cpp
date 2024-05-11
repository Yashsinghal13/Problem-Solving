//Recursion Approach
// class Solution {
// public:
//     void nops(int n,vector<int> v,int &mine,int sum,int index,int &c)
//     {
//         if(sum==n)
//         {
//             cout<<sum<<endl;
//             if(mine>c)
//             {
//                 mine=c;
//                 c=0;
//                 return ;
//             }
//             return ;
//         }
//         else if(sum>n || index>=v.size())
//         {
//             c=0;
//             return;
//         }
//         c++;
//         cout<<sum<<endl;
//         nops(n,v,mine,sum+v[index],index++,c);
//         nops(n,v,mine,sum,index,c);
//     }

//     int numSquares(int n) {
//         vector<int> v;
//         int ps=1;
//         while(ps*ps<=n)
//         {
//             v.push_back(ps*ps);
//             ps++;
//         }
//         int mine=INT_MAX,c=0,sum=0,index=0;
//         nops(n,v,mine,sum,index,c);
//         return mine;
        
//     }
// };

//Recursion+Memoization
class Solution {
public:
    int solve(int n,vector<int>&cache)
    {
        if(n==0) return 0;
        if(cache[n]!=-1) return cache[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1+solve(n-i*i,cache));
            cache[n]=ans;
        }
        return ans;
    }
    int numSquares(int n) {
        vector<int> cache(n+1,-1);
        return solve(n,cache);
    }
};