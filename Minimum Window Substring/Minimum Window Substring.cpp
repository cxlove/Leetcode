
class Solution {
public:
    string minWindow(string s, string t) {
        int a[200] , b[200] , cnt = 0 , tot = 0 , ans = 1 << 30 , idx;
        memset (a , 0 , sizeof (a));
        for (int i = 0 ; i < t.size () ; i ++) {
            if (!a[t[i]] ++) cnt ++;
        }
        memset (b , 0 , sizeof (b));
        for (int i = 0 , j = 0 ; i < s.size () ; i ++) {
            while (tot < cnt && j < s.size ()) {
                if (++ b[s[j]] == a[s[j]]) tot ++;
                j ++;
            }
            if (cnt == tot) {
                if (j - i < ans) {
                    ans = j - i;
                    idx = i;
                }
            }
            if (b[s[i]] -- == a[s[i]]) tot --;
        }
        if (ans == 1 << 30) return "";
        return s.substr (idx , ans);
    }
};