// jai shree ram
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<int> m(n*n+1,0);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                m[grid[i][j]]++;
            }
        }
        int x = 0 , y = 0;
        for(int i = 0 ; i <= n*n ; i++)
        {
           
                if(m[i] > 1)
                x = i;
                
                else
                
                if(m[i] == 0)
                y = i;
            
        }
        return {x,y};
    }
};
