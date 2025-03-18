// jai shree ram
class Solution {
public:
    int longestNiceSubarray(vector<int>& A) {
        int n = A.size();
        int j  = 0;
        int len = 0;
        int x = 0;
        for(int i = 0 ; i < n ; i++) {
            while(x & A[i]) {
                x = x ^ A[j++];
            }
            x = x | A[i];
            len = max(len , i - j + 1);
        }
        return len;
    }
};
