class UnionFind {
    public:
    UnionFind(int n): id(n), rank(n) {
        iota(id.begin(), id.end(), 0);
    }

    bool unionByRank(int i, int j) {
        int u = find(i);
        int v = find(j);

        if(u==v)
        return false;
        
        if(rank[u] <= rank[v])
        {   
            if(rank[u] == rank[v])
            ++rank[v];

            id[u] = v;
        } else 
        {
            id[v] = u;
        }

        return true;
    }

    private:
    vector<int> id;
    vector<int> rank;

    int find(int u) {
        return (id[u] == u)? u: id[u] = find(id[u]);
    }

};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n  = edges.size();

        vector<int> indeg(n+1, 0);
        int nodeWithTwoPar = 0;

        for(const vector<int>& edge: edges) {
            const int v = edge[1];
            if(++indeg[v] == 2) {
                nodeWithTwoPar = v;
                break;
            }
        }

        if(nodeWithTwoPar == 0)
        return findRedundantEdge(edges, -1);

        for(int i=n-1; i>=0; i--) {
            if(edges[i][1] == nodeWithTwoPar) {

                if(findRedundantEdge(edges, i).empty())
                return edges[i];
            }
        }

        return {};
    }
    vector<int> findRedundantEdge(const vector<vector<int>>& edges, int skip) {
        int n = edges.size();
        UnionFind uf(n+1);

        for(int i=0; i<n; i++) {
            if(i == skip)
            continue;

            if(!uf.unionByRank(edges[i][0], edges[i][1]))
            return edges[i];
        }

        return {};
    }
};