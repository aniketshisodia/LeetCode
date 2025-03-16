// jai shree ram
#define ll long long
class Solution {
    bool f(ll mid , vector<int> &A , int k) {
        ll count = 0;
        for(int i = 0 ; i < A.size(); i++) {
            ll n = sqrt(mid / A[i]);
            count += n;
        }
        return count >= k;
    }
public:
    long long repairCars(vector<int>& A, int cars) {
        int n = A.size();
        
        ll low = 1; 
        ll high = 1e18;

        ll ans;

        while(low <= high) {
            ll mid = (low + high) / 2;
            if(f(mid , A , cars)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
