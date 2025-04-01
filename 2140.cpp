// jai shree ram
class Solution {
public:
    long long mostPoints(vector<vector<int>>& A) {
        
        long long n = A.size();
        
        vector<long long> dp(n , 0);
        
        for(int i = n-1; i >= 0; i--) {
            long long exc = 0 ;
            long long inc = A[i][0];
            // inc
            if(A[i][1] + i + 1 < n) {
                inc += dp[A[i][1] + i + 1];
            }
            if(i + 1 < n)
            exc = dp[i + 1];

            dp[i] = max(inc , exc);
        }

        return dp[0];

    }
};
