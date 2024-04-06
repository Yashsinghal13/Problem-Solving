#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool checkingBST1child(vector<int> &preorder)
{
    for(int i=0;i<preorder.size()-1;i++)
    {
        int decreasing=0,increasing=0;
        for(int j=i+1;j<preorder.size();j++)
        {
            if(preorder[i]>preorder[j]){
                decreasing =1;
            }
            else
            {
                increasing=1;
            }
            if(decreasing==1 && increasing==1) return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    cout<<"Enter The Preorder of BST"<<endl;
    vector<int> preorder(n);
    bool check=checkingBST1child(preorder);
    if(check) cout<<"Yes";
    else cout<<"No";

}