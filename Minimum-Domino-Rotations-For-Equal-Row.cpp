// jai shree ram
class Solution {
public:
    int minDominoRotations(vector<int>& T, vector<int>& B) {
        int n = T.size();
        int mini = INT_MAX;
        for(int num=1 ; num <= 6; num++) {
            int f1 = 1 , f2 = 1;
            int op = 0 , op2 = 0;
            for(int i = 0; i < n; i++) {
                // try tops to become equal to num
                if(T[i] == num) {
                    continue;
                }
                else
                if(B[i] == num) {
                    op++;
                }
                else {
                    f1 = 0;
                    break;
                }
            }
            if(f1) {
                mini = min(mini , op);
            }
        }
        for(int num=1 ; num <= 6; num++) {
            int f1 = 1 , f2 = 1;
            int op = 0 , op2 = 0;
            for(int i = 0; i < n; i++) {
                // try tops to become equal to num
                if(B[i] == num) {
                    continue;
                }
                else
                if(T[i] == num) {
                    op++;
                }
                else {
                    f1 = 0;
                    break;
                }
            }
            if(f1) {
                mini = min(mini , op);
            }
        }
        
        if(mini == INT_MAX) {
            return -1;
        }
        return mini;
    }
};
