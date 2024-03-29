int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<int,vector<int>,greater<int>>pq;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          pq.push(mat[i][j]);
      }
  }
  int i=1;
  while(i<k)
  {
      pq.pop();
      i++;
  }
  return pq.top();
}