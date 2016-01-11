class Solution {
public:
    vector <vector <int> > dp;
    vector <vector <vector <pair <int , int> > > > path;
    void update (int l , int r , int x , int y , int val) {
        if (val > dp[l][r]) {
            dp[l][r] = val;
            path[l][r].clear ();
            path[l][r].push
        }
    }

    int getDp (int l , int r , string &s) {
        if (l >= r) return 0;
        if (s[l] == s[r]) {
            update (l , r , l + 1 , r - 1 , getDp (l + 1 , r - 1 , s) + 2);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = (int)s.length ();
        vector <string> ans;
        if (n == 0) return ans;
        dp.resize (n , vector <int> (n , -1));
        path.resize (n , vector <vector <pair <int , int> > >(n));
        getDp (0 , n - 1 , s);
    }
};