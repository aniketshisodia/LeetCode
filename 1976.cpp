// jai shree ram
#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        ll mod = 1e9+7;

        
        vector<vector<ll>> list[n]; 
        
        for(int i = 0 ; i < roads.size() ; i++) {
           list[roads[i][0]].push_back({roads[i][1] , roads[i][2]});
           list[roads[i][1]].push_back({roads[i][0] , roads[i][2]});
        }

        // queue<pair<int,int>> q;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        
        vector<ll> dist(n , LONG_MAX) , reach(n);
        reach[0] = 1;
        dist[0] = 0;
        
        q.push({0 , 0});
      
        while(!q.empty()) 
        { 
            ll node = q.top().second;
            ll dis = q.top().first;
            q.pop();

            for(auto it : list[node]) {
               
                ll edge = it[1];
                ll adjNode = it[0];
                
                    if(dis + edge < dist[adjNode]) 
                    {
                      dist[adjNode] = dis + edge; 
                      q.push({dis + edge , adjNode});
                      reach[adjNode] = reach[node];
                    }

                    else 
                    if(dis + edge == dist[adjNode]) 
                    {
                      reach[adjNode] = (reach[adjNode] + reach[node]) % mod;  
                    }
            }
        }

        return reach[n-1] % mod;
    }
};
