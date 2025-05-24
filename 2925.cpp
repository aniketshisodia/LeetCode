// jai shree ram

// took help , saw solution
// Appraoch wass correct, my imp was different

class Solution {
public:
    vector<vector<int>> adj;

    // DFS to compute minimum value we must keep in this subtree
    long long dfs(int node, int parent, vector<int>& values) {
        long long keep = 0;
        bool isLeaf = true;

        for (int child : adj[node]) {
            if (child == parent) continue;
            isLeaf = false;
            keep += dfs(child, node, values);
        }

        // If it's a leaf, we must keep its value to ensure path sum is not zero
        if (isLeaf) return (long long) values[node];

        // For non-leaf, either keep own value or children's keep sum — whichever is smaller
        return min((long long)values[node], keep);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        adj.resize(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        long long totalSum = 0;
        for (int v : values) totalSum += (long long)v;

        long long mustKeep = dfs(0, -1, values);
        cout << mustKeep << " " << totalSum;
        return totalSum - mustKeep;
    }
};
