// jai shree ram
#define ll long long
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& A, int mod, int k) {
        map<int, ll> mp;
        mp[0] = 1; // base case

        ll count = 0;
        int prefix = 0;

        for (int i = 0; i < A.size(); ++i) {
            if (A[i] % mod == k) prefix++;
            int rem = prefix % mod;
            int need = ((rem - k) % mod + mod) % mod;

            if (mp.find(need) != mp.end()) {
                count += mp[need];
            }
            mp[rem]++;
        }
        return count;
    }
};
