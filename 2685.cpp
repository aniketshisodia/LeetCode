// jai shree ram
class Solution {
    vector<int> vis;
    vector<vector<int>> adj;
    void dfs(int node , vector<int> &v) {
        vis[node] = 1;
        v.push_back(node);
        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                dfs(adjNode , v);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n , 0);
        int ans = 0;
        // 1. create graph
        for(auto it : edges) {
            int u = it[0] , v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 2. traverse node and run dfs
        for(int node = 0; node < n; node++) {
            vector<int> v;
            if(!vis[node])
                dfs(node , v);
            else continue;
            int f = 0;
            for(auto it : v) {
                // cout << it << " ";
                if(adj[it].size() != v.size()-1) f = 1;
            }
            cout << endl;
            if(!f) ans++;
        }
        return ans;
    }
};
