// jai shree ram
class Solution {
public:
    int minCost(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e5));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // right, left, down, up
        int drow[4] = {0, 0, 1, -1};
        int dcol[4] = {1, -1, 0, 0};
        
        while (!pq.empty()) {
            auto [op, p] = pq.top();
            int i = p.first, j = p.second;
            pq.pop();

            // Skip if already found a shorter distance
            if (op > dist[i][j]) continue;
            
            if (i == n - 1 && j == m - 1)
                return op;

            for (int s = 0; s < 4; s++) {
                int nrow = i + drow[s];
                int ncol = j + dcol[s];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newCost = (s + 1 == A[i][j]) ? op : op + 1;
                    
                    if (dist[nrow][ncol] > newCost) {
                        dist[nrow][ncol] = newCost;
                        pq.push({newCost, {nrow, ncol}});
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};
