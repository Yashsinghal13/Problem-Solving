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
        if(mid+1<n && (nums[mid]>nums[mid+1]))
        {
            return mid;
        }
        else if((mid-1>=0) && nums[mid-1]>nums[mid])
        {
            return mid-1;
        }
        else if(nums[mid]<nums[low])
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
int binarySearch(vector<int> &nums,int target,int low,int high)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]>target){return binarySearch(nums,target,low,mid-1);}
    else{ return binarySearch(nums,target,mid+1,high);}
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
    int target;
    cin>>target;
    int pivot=peakele(nums);
    int ans =-1;
    if(nums[0]<=target && target<=nums[pivot])
    {
        int low=0,high=pivot;
        ans=binarySearch(nums,target,0,pivot);
    }
    else
    {
        ans=binarySearch(nums,target,pivot+1,nums.size()-1);
    }
    cout<<ans;

    return 0;
}