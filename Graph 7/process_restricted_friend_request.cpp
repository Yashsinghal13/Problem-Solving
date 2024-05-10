class DisjointSet 
{
public:
    vector<int> parent, size;
    DisjointSet(int n) 
    {
        parent.resize(n);
        size.resize(n);
        for(int x=0; x<n; x++) 
        {
            parent[x]=x;
            size[x]=1;
        }
    }

    int findPar(int node) 
    {
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionn(int u, int v) 
    {
        int upar=findPar(u);
        int vpar=findPar(v);
        if(upar==vpar) return;
        if(size[upar]<size[vpar]) 
        {
            parent[upar]=vpar;
            size[vpar]+=size[upar];
        }
        else 
        {
            parent[vpar]=upar;
            size[upar]+=size[vpar];
        }
    }
};
class Solution 
{
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) 
    {
        vector<bool> ans;
        DisjointSet ds(n);
        for(auto request: requests)
        {
            DisjointSet prev=ds;
            ds.unionn(request[0],request[1]);
            bool success=true;
            for(auto restriction: restrictions)
            {
                if(ds.findPar(restriction[0])==ds.findPar(restriction[1]))
                {
                    success=false;
                    break;
                }
            }
            if(success) ans.push_back(true);
            else
            {
                ds=prev;
                ans.push_back(false);
            }
        }
        return ans;
    }
};