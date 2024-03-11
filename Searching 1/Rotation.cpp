#include<iostream>
#include<vector>
using namespace std;
int minimumPivotIndex(vector<int> &arr)
{
    int n=arr.size()-1;
    int low=0,high=n-1;
    while(low<high)
    {
        int mid=(low+high)/2;
        if(mid+1<n && arr[mid]>arr[mid+1])
        {
            return mid+1;
        }
        else if(mid-1>=0 && arr[mid-1]>arr[mid])
        {
            return mid;
        }
        else if(arr[mid]<arr[high])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int ans=minimumPivotIndex(nums);
    cout<<ans;

    return 0;
}