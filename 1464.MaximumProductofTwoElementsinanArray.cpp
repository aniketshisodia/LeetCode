// jai shree ram
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int c = 0;
        for(int i = 0 ; i < startTime.size() ; i++){
            if(startTime[i] + endTime[i] > queryTime)
              c++;
        }
        return c;
    }
};
