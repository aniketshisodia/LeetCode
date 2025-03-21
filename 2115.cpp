// jai shree ram
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end());
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        
        for (int i = 0; i < recipes.size(); i++) {
            for (auto& ing : ingredients[i]) {
                if (!available.count(ing)) { 
                    graph[ing].push_back(recipes[i]);  
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for (int i = 0; i < recipes.size(); i++) {
            if (indegree[recipes[i]] == 0) {
                q.push(recipes[i]);
            }
        }

        vector<string> result;
        while (!q.empty()) {
            string recipe = q.front();
            q.pop();
            result.push_back(recipe);
            
            for (auto& dependent : graph[recipe]) {
                if (--indegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }

        return result;
    }
};
