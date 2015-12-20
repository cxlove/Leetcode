class Solution {
public:
    vector <vector <string> > ans;
    bool isPali (string &s , int l , int r) {
        while (l < r) {
            if (s[l ++] != s[r --]) return false;
        }
        return true;
    }
    void dfs (vector <string> &ret , string &s , int pos) {
        if (pos >= (int)s.length ()) {
            ans.push_back (ret);
            return ;
        }
        string p = "";
        for (int i = pos ; i < (int)s.length () ; i ++) {
            p += s[i];
            if (isPali (s , pos , i)) {
                ret.push_back (p);
                dfs (ret , s , i + 1);
                ret.pop_back ();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.clear ();
        vector <string> ret;
        dfs (ret , s , 0);
        return ans;
    }
};