class Solution
{
public:
    bool ispossible(int arr[],int n,int k,long long mid){
        long long time=0;
        long long c=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
            {
                return false;
            }
            if(time+arr[i]>mid)
            {
                c++;
                if(c>k)
                {
                    return false;
                }
                time=arr[i];
            }
            else
            {
                time+=arr[i];
            }
        }
        return true;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long s=0,e=0,ans=-1;
        for(int i=0;i<n;i++)
        {
            e+=arr[i];
        }
        //cout<<e<<endl;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(ispossible(arr,n,k,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
        
    }
};