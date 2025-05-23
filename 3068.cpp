// jai shree ram
#define ll long long
class Solution {
    ll f(int index, vector<int> &A , int isEven , vector<vector<ll>> &dp , int k) {
        if(index == A.size()) {
            return isEven == 1 ? 0 : INT_MIN;
        }
        if(dp[index][isEven] != -1)
        return dp[index][isEven];
        ll notTake = A[index] + f(index+1 , A , isEven , dp ,  k);
        ll take = (A[index] ^ k) + f(index+1 , A , 1 ^ isEven , dp , k );

        return dp[index][isEven] = max(take , notTake);
    }
public:
    long long maximumValueSum(vector<int>& A, int k, vector<vector<int>>& edges) {
        ll n = A.size();
        vector<vector<ll>> dp(n , vector<ll> (2 , -1)); 
        return f(0 , A , 1 , dp , k);
    }
};
