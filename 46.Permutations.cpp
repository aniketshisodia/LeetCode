// jai shree ram 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer ;
        int index = 0 ;
        SolveRec(nums,answer ,index );
        return answer ;
    }

       void SolveRec(vector<int> nums,vector<vector<int>> & answer ,  int index ){
        // base case;
        if( index >= nums.size()){
            answer.push_back(nums);
            return ;
        }
        // main 
        for(int j = index; j < nums.size() ; j++){
              swap(nums[index],nums[j]);
              SolveRec(nums,answer, index+1);
              // reverse
              swap(nums[index],nums[j]);
        }

    }
};
