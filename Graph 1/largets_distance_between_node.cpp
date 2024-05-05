#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findFarthestNode(vector<vector<int>>& adj, int root, vector<bool>& vis) {
        if (vis[root]) {
            return {root, 1};
        }
        vis[root] = true;
        int maxi = 0;
        int farthestNode = root;
        for (int i : adj[root]) {
            if (!vis[i]) {
                vector<int> val = findFarthestNode(adj, i, vis);
                if (1 + val[1] > maxi) {
                    maxi = 1 + val[1];
                    farthestNode = val[0];
                }
            }
        }
        return {farthestNode, maxi};
    }

    int maxDis(vector<vector<int>>& adj, int root, vector<bool>& vis) {
        if (vis[root]) {
            return 1;
        }
        vis[root] = true;
        int maxi = 0;
        for (int i : adj[root]) {
            if (!vis[i]) {
                int val = maxDis(adj, i, vis);
                if (1 + val > maxi) {
                    maxi = 1 + val;
                }
            }
        }
        return maxi;
    }

    int solve(vector<int>& A) {
        vector<vector<int>> adj(A.size());
        int n = A.size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == -1) {
                start = i;
                continue;
            }
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }

        vector<bool> vis(A.size(), false);

        vector<int> farthestNode = findFarthestNode(adj, start, vis);

        fill(vis.begin(), vis.end(), false);
        int res = maxDis(adj, farthestNode[0], vis);

        return res;
    }
};
