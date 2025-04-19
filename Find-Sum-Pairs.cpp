// jai shree ram
class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;

    FindSumPairs(vector<int>& A, vector<int>& B) {
        nums1 = A;
        nums2 = B;
        for (int x : nums1) freq[x]++;
    }
    
    void add(int index, int val) {
        nums2[index] += val;
    }
    
    int count(int tot) {
        int c = 0;
        for (int y : nums2) {
            int x = tot - y;
            if (freq.count(x)) {
                c += freq[x];
            }
        }
        return c;
    }
};
