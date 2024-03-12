int NthRoot(int n, int m)
{
    if(m==1 || n==1) return m;
    int val=pow(10,(9/n+1));
    int low=0,high=min(m,val);
    while(low<=high)
    {
        int mid=low+((high-low)/2);
        long long mul=1;
        for(int i=1;i<=n;i++)
        {
            mul=mul*mid;
            if(mul>m) break;
        }
        if(mul==m) return mid;
        else if(mul>m) high=mid-1;
        else low=mid+1;
    }
    return -1;
}  