class Union{
    int *size,*parent,n;
    public:
    Union(int n){
        this->n=n;
        size=new int[n+1];
        parent=new int[n+1];
        for(int i=1;i<n+1;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int find(int n){
        if(n!=parent[n]){
            parent[n]=find(parent[n]);
        }
        return parent[n];
    }
    void add(int u,int v){
        int up=find(u);int vp=find(v);
        int ups=size[up],vps=size[vp];
        if(ups>vps){
            parent[vp]=up;
            size[up]+=size[vp];
        }
        else{
            parent[up]=vp;
            size[vp]+=size[up];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        Union up(edges.size());
        for(auto i:edges){
            if(up.find(i[0])==up.find(i[1]))ans.push_back({i[0],i[1]});
            up.add(i[0],i[1]);
        }
        return ans[ans.size()-1];
    }
};