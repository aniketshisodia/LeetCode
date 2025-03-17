// jai shree ram
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it : nums) {
            mp[it]++;
        }
        for(auto [f,s] : mp) {
            if(s % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
