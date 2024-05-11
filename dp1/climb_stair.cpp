class Solution{
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
        {
            return 1;
        }
       else{
           int c,a=1,b=1;
           for(int i=2;i<=n;i++)
           {
               c=a+b;
               a=b;
               b=c;
           }
           return c;
       }


    }
};