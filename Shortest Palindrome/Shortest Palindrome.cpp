t int HASH = 1000000007;
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size ();
        if (n == 0) return s;
        vector <int> p (n + 1);
        vector <int> h (n + 1);
        vector <int> r (n + 1);
        p[0] = 1;
        for (int i = 1 ; i <= n ; i ++) {
            p[i] = p[i - 1] * HASH;
        }
        r[n] = 0;
        for (int i = n - 1 ; i >= 0 ; i --) {
            r[i] = r[i + 1] * HASH + s[i];
        }
        h[0] = 0;
        for (int i = 1 ; i <= n ; i ++) {
            h[i] = h[i - 1] * HASH + s[i - 1];
        }
        
        int ans = 1;
        for (int i = 1 ; i * 2 + 1 <= n ; i ++) {
            int A = h[i];
            // i + 1 ~ i + 1 + i - 1
            int B = r[i + 1] - r[i + 1 + i - 1 + 1] * p[i];
            if (A == B) {
                ans = max (ans , i * 2 + 1);
            }
        }
        for (int i = 1 ; i * 2 <= n ; i ++) {
            int A = h[i];
            // i ~ i + i - 1
            int B = r[i] - r[i + i - 1 + 1] * p[i];
            if (A == B) {
                ans = max (ans , i * 2);
            }
        }
        string ret = s;
        reverse (ret.begin () , ret.end ());
        for (int i = ans ; i < n ; i ++) {
            ret += s[i];
        }
        return ret;
    }
};
