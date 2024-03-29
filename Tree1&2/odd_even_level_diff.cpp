class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       int evenlevelsum=0,oddlevelsum=0,sum=0;
       int i=0;
       queue<Node*> q;
       q.push(root);
       q.push(NULL);
       while(!q.empty())
       {
           Node *node=q.front();
           q.pop();
           if(node==NULL)
           {
               if(!q.empty())
               {
                   
                   if(i%2==0)
                   {
                       evenlevelsum+=sum;
                   }
                   else
                    {
                       oddlevelsum+=sum;
                    }
                    sum=0;
                    q.push(NULL);
                    i++;
                   
               }
               else
               {
                    if(i%2==0)
                   {
                       evenlevelsum+=sum;
                   }
                   else
                    {
                       oddlevelsum+=sum;
                    }
               }
           }
           else
           {
               sum=sum+node->data;
               if(node->left!=NULL) q.push(node->left);
               if(node->right!=NULL) q.push(node->right);
           }
       }
       return evenlevelsum-oddlevelsum;
       
    }
};