#include<iostream>
#include<vector>
using namespace std;
int peakele(vector<int> &nums)
{
    int n=nums.size();
    int low=0,high=n-1;
    while(low<high)
    {
        int mid=(low+high)/2;
        if(mid+1<n && nums[mid]>nums[mid+1])
        {
            return mid+1;
        }
        else if(mid-1>=0 && nums[mid]<nums[mid-1])
        {
            return mid;
        }
        else if(nums[mid]<nums[high])
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
    int ans=peakele(nums);
    cout<<nums[ans];
    return 0;
}