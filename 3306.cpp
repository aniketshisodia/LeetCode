// jai shree ram
#define ll long long 
class Solution {
    bool isVowel(char ch) {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
        return false; 
    }
    // check vowels 
    bool f(unordered_map<char,int> &mp) {
        for(auto it: mp) {
            if(it.second == 0) return false;
        }
        return true;
    }
    ll f(string s , int k) {
        int n = s.size();
        int j = 0;
        int cc = 0;
        ll ans = 0;
        unordered_map<char,int> mp;
        mp['a'] = 0;
        mp['e'] = 0;
        mp['o'] = 0;
        mp['i'] = 0;
        mp['u'] = 0;
        for(int i = 0 ; i < n ; i++) {
            if(isVowel(s[i])) {
                mp[s[i]]++;
            }
            else cc++;
            while(f(mp) && cc >= k) {
                ans += n - i;
                if(isVowel(s[j])) {
                    mp[s[j]]--;
                }
                else
                cc--;
                j++;
            }
        }
        return ans;
    }
public:
    long long countOfSubstrings(string s, int k) {
        return f(s , k) - f(s , k + 1);
    }
};
