// Jai Shree Ram
class Solution {
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &A) {
        int res = 0;
        for (auto adjNode : adj[node]) {
            if (adjNode == parent) continue; // Avoid revisiting the parent
            int childRes = dfs(adjNode, node, adj, A);
            if (childRes > 0 || A[adjNode]) {
                res += childRes + 2; // Add 2 for the round trip if there's an apple
            }
        }
        return res;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto &it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Convert to an undirected graph
        }
        return dfs(0, -1, adj, hasApple);
    }
};
