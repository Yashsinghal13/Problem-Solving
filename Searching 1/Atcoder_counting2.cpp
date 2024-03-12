#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  int n,q;
  cin>>n>>q;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  vector<int> Q(q);
  for(int i=0;i<q;i++)
  {
    cin>>Q[i];
  }
  sort(arr.begin(),arr.end());
  for(int i=0;i<q;i++)
  {
    int low=0,high=n-1;
    int c=0;
    while(low<=high)
    {
      int mid=low+((high-low)/2);
      if(arr[mid]>=Q[i])
      {
        c=n-mid;
        high=mid-1;
      }
      else
      {
        low=mid+1;
      }
    }
    cout<<c<<endl;
  }
  return 0;
}