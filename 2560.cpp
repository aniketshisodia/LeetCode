// jai shree ram
class Solution {
    bool isPossible(int val , vector<int> &A , int k) {
        int i = 0 , count = 0;
        while(i < A.size()) {
            if(A[i] <= val) {
                i+=2;
                count++;
            }
            else {
                i++;
            }
        }
        return count >= k;
    }
public:
    int minCapability(vector<int>& A, int k) {
        int low  = *min_element(A.begin() , A.end());
        int high = *max_element(A.begin() , A.end());
        int ans;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(mid , A , k)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
