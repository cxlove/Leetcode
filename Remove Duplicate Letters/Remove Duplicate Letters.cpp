class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector <int> cnt (26 , 0);
        vector <int> in (26 , 0);
        string ans;
        for (char ch : s) {
            cnt[ch - 'a'] ++;
        }
        for (char ch : s) {
            cnt[ch - 'a'] --;
            if (in[ch - 'a']) continue;
            while (!ans.empty () && ch < ans.back () && cnt[ans.back () - 'a']) {
                in[ans.back () - 'a'] = 0;
                ans.pop_back ();
            }
            ans += ch;
            in[ch - 'a'] = 1;
        }
        return ans;
    }
};
