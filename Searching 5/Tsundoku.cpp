#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> A(n);
  vector<int> B(m);
  for(int i=0;i<n;i++)
  {
    cin>>A[i];
  }
  for(int j=0;j<m;j++){
    cin>>B[j];}
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  int count=0;
  int i=0,j=0,flag=0;
  while(i<n && j<m)
  {
    if(A[i]<B[j])
    {
      if(A[i]<=k){
        k=k-A[i];
        count++;
        i++;}
      else{
        flag=1;
        break;}
    }
    else
    {
      if(B[j]<=k){
        k=k-B[j];
        count++;
        j++;}
      else{
        flag=1;
        break;}
    }
  }
  if(flag==0)
  {
    if(i<n){
      while(i<n && A[i]<=k)
      {
        k=k-A[i];
        count++;
        i++;
      }
    }
    else
    {
      while(j<m && B[j]<=k)
      {
        k=k-B[j];
        count++;
        j++;
      }
    }
  }
  cout<<count;
  return 0;
}