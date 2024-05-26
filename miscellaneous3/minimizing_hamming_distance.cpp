class disjointset
{
private:
	
public:
    vector<int>rank, par;
	disjointset(int n) {
		rank.resize(n + 1, 0);
		par.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			par[i] = i;
		}
	}
	int findpar(int u) {
		if (u == par[u]) {
			return u;
		}
		return par[u] = findpar(par[par[u]]);
	}
	void unionrank(int u, int v) {
		int pu = findpar(u);
		int pv = findpar(v);
		if (pu == pv) {
			return;
		}
		else if (rank[pu] < rank[pv]) {
			par[pu] = pv;
		}
		else if (rank[pv] < rank[pu]) {
			par[pv] = pu;
		}
		else if (rank[pu] == rank[pv]) {
			par[pv] = pu;
			rank[pu]++;

		}
	}

};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        disjointset ds(100005);
        map<int,multiset<int>>mp;
				for(auto x: allowedSwaps){
					int u=x[0];
					int v=x[1];
					ds.unionrank(u,v);
				}
				for(int i=0;i<n;i++){
					int a=ds.findpar(i);
					mp[a].insert(source[i]);
				}
				int ans=0;
				for(int i=0;i<n;i++){
					int u=source[i];
					int v=target[i];
					
					if(mp[ds.findpar(i)].find(v)!=mp[ds.findpar(i)].end()){
                        mp[ds.findpar(i)].erase(mp[ds.findpar(i)].find(v));

                    }
                    else{
                        ans++;
                    }

				}
				return ans;


        
        
        
    }
};