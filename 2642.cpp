// Jai Shree Ram
class Graph {
    vector<vector<pair<int, int>>> adj;
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }
    }

    void addEdge(vector<int> e) {
        adj[e[0]].push_back({e[1], e[2]});
    }

    int shortestPath(int node1, int node2) {
        vector<int> dist(n, 1e9);
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;
            vis[node] = true;

            for (auto& [adjNode, wt] : adj[node]) {
                if (dist[adjNode] > dis + wt) {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return (dist[node2] == 1e9) ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
