// jai shree ram
class Solution {
    int remove(string &s, string sub, int val) {
        stack<char> st;
        string temp;
        int ans = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == sub[0] && c == sub[1]) {
                st.pop();
                ans += val;
            } else {
                st.push(c);
            }
        }

        temp = "";
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;

        return ans;
    }

public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if (x > y) {
            ans += remove(s, "ab", x);
            ans += remove(s, "ba", y);
        } else {
            ans += remove(s, "ba", y);
            ans += remove(s, "ab", x);
        }
        return ans;
    }
};
x1717
