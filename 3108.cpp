// jai shree ram
class DisjointSet {
private:
    vector<int> parent, size, wt;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        wt.resize(n + 1, 131071); // Initialize with 131071 (binary 11111111111111111)
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v, int w) {
        int uu = find(u);
        int vv = find(v);
        if (uu == vv) {
            wt[uu] &= w; // Update weight if already in the same set
            return;
        }

        if (size[uu] >= size[vv]) {
            parent[vv] = uu;
            size[uu] += size[vv];
            wt[uu] &= wt[vv] & w; // Update weight using bitwise AND
        } else {
            parent[uu] = vv;
            size[vv] += size[uu];
            wt[vv] &= wt[uu] & w; // Update weight using bitwise AND
        }
    }

    int q(int u, int v) {
        if (u == v) return 0; // If same node, cost is 0
        int uu = find(u);
        int vv = find(v);
        if (uu != vv) return -1; // If not connected, return -1
        return wt[uu]; // Return the weight of the connected component
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        DisjointSet ds(n);

        for (auto& it : edges) {
            ds.Union(it[0], it[1], it[2]);
        }

        for (auto& it : query) {
            ans.push_back(ds.q(it[0], it[1]));
        }
        return ans; 
    }
};
