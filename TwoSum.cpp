// jai shree ram
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        int j;
        vector<int> ans;
        int i=0;
        
        while(i<nums.size()-1)
        {
          j=i+1;
          while(j<nums.size())
          {
            if(target-nums[i]==nums[j])
            {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            j++;
          }
        i++;
        }
       return ans; 
    }
};
