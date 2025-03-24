// jai shree ram
class Solution {
public:
    int countDays(int days, vector<vector<int>>& A) {
        sort(A.begin(), A.end());  
        int free = 0, curr = 1;

        for (auto& it : A) {
            int s = it[0], e = it[1];
            if (curr < s) {  
                free += (s - curr);
            }
            curr = max(curr, e + 1);
        }

        if (curr <= days) {  
            free += (days - curr + 1);
        }

        return free;
    }
};
