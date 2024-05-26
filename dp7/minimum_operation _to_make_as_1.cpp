#include <iostream>
#include<climits>
#include<vector>
using namespace std;
int op(int n,vector<int>&cache)
{
    if(n==1) return 0;
    if(cache[n]!=-1) return cache[n];
    int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
    if(n%2==0)
    {
        op1=1+op(n/2,cache);
    }
    if(n%3==0)
    {
        op2=1+op(n/3,cache);
    }
    op3=1+op(n-1,cache);
    cache[n]=min(op1,min(op2,op3));
    return cache[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int>cache(n+1,-1);
    cout<<op(n,cache);
    return 0;
}
