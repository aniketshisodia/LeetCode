// jai shree ram 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int maxi = max(m,n);
        vector<vector<int>> dp(maxi + 1 , vector<int>(maxi + 1, -1));

        int ans = solve(m , n , dp);

        return ans;
    }
    int solve(int i , int j , vector<vector<int>> &dp ){
        
        if(i==1&&j==1) return 1;
        
        if(i==0||j==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        if(dp[j][i]!=-1) return dp[j][i];

        dp[i][j] = solve(i-1,j,dp) + solve(i,j-1,dp);
        return dp[i][j];
    }
};
