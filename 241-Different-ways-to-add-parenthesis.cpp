// jai shree ram
class Solution {
    int perform(int x , int y , char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    } 
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        int isNum = 1;
        for(int i = 0 ; i < exp.size() ; i++) {
            if(!isdigit(exp[i])) {
                isNum = 0;
                vector<int> left = diffWaysToCompute(exp.substr(0 , i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));
                // cout<<left.size() <<" "<<right.size()<<endl<<endl;
                for(int x : left) {
                    for(int y : right) {
                        cout<<x<<" "<<y<<endl;
                        int val = perform(x , y , exp[i]);
                        res.push_back(val);
                    }
                }
                cout<<endl;
            }
        }
        if(isNum) {
            res.push_back(stoi(exp));
        }
        return res;
    }
};
