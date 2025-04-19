// jai shree ram
class FindSumPairs {
    vector<int> A , B;
    map<int,int> first;
    unordered_map<int,int> second;
public:

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        A=nums1;
        B=nums2;
        for(auto it : nums1) first[it]++;
        for(auto it : nums2) second[it]++;
    }
    
    void add(int index, int val) {
        second[B[index]]--;
        B[index]+=val;
        second[B[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(auto [x , f] : first) {
            if(second.count(tot - x)) {
                c += f*second[tot-x];
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
