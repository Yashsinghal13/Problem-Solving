#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    int size;
    cin>>size;
    int i=0,j=0;
    int tempsum=0;
    int c=0;
    while(j<arr.size())
    {
        tempsum=tempsum+arr[j];
        if(tempsum<sum && j-i+1==size)
        {
            c++;
        }
        else if(tempsum>=sum)
        {
            while(i<=j && tempsum>=sum)
            {
                tempsum-=arr[i];
                i++;
            }
        }
        j++;
    }
    cout<<c;
    return 0;
}