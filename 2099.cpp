// jai shree ram
class Solution {
public:
    int minOperations(vector<int>& A) {
        int n = A.size();
        int ans = n;
        set<int> unique(A.begin(),A.end());
        vector<int> newA;
        for(int num : unique) {
            newA.push_back(num);
        }
        for(int i = 0 ; i < newA.size(); i++) {
            int left = newA[i];
            int right = left + n - 1;

            int j = upper_bound(newA.begin(),newA.end(),right) - newA.begin();
            int count = j-i;
            ans = min(ans , n - count);
        }
        return ans;
    }
};
