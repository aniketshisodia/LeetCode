// jai shree ram
#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& A, int k) {
        int n = A.size();
        int j = 0;
        ll count = 0;
        ll ans = 0;
        ll maxi = *max_element(A.begin() , A.end());
        for(int i = 0 ; i < n; i++) {
            if(A[i] == maxi) {
                count++;
            }
            while(count >= k) {
                if(A[j] == maxi) {
                    count--;
                }
                j++;
                ans += n-i;
            }
        }
        return ans;
    }
};
