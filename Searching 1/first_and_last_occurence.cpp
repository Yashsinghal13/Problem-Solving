#include<iostream>
#include<vector>
using namespace std;
int findFirstOccurence(vector<int> &nums,int target)
{
    int low=0,high=nums.size()-1;
    int indexfirstoccurence=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            indexfirstoccurence=mid;
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return indexfirstoccurence;
}
int findLastOccurence(vector<int> &nums,int target)
{
    int low=0,high=nums.size()-1;
    int indexlastoccurence=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            indexlastoccurence=mid;
            low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return indexlastoccurence;
}
int main()
{
    int n,target;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cin>>target;
    vector<int> ans(2,-1);
    ans[0]=findFirstOccurence(nums,target);
    ans[1]=findLastOccurence(nums,target);
    cout<<ans[0]<<" "<<ans[1];

}