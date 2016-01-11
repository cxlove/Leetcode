class Solution {
public:
    string add (string a , string b) {
        string ans = "";
        reverse (a.begin () , a.end ());
        reverse (b.begin () , b.end ());
        int sum = 0;
        for (int i = 0 , j = 0 ; i < (int)a.size () || j < (int)b.size () ; i ++ , j ++) {
            if (i < (int)a.size ()) sum += a[i] - '0';
            if (j < (int)b.size ()) sum += b[i] - '0';
            ans += char (sum % 10 + '0');
            sum /= 10;
        }
        if (sum) ans += char (sum + '0');
        reverse (ans.begin () , ans.end ());
        return ans;
    }
    bool isAdditiveNumber(string num) {
        int n = num.size ();
        if (n < 3) return false;
        for (int i = 1 ; i < n ; i ++) {
            for (int j = 1 ; j + i < n ; j ++) {
                string A[2];
                A[0] = num.substr (0 , i);
                A[1] = num.substr (i , j);
                if (A[0].size () > 1 && A[0][0] == '0') continue;
                if (A[1].size () > 1 && A[1][0] == '0') continue;
                string ret = A[0] + A[1];
                int idx = 0;
                while ((int)ret.size () < num.size ()) {
                    A[idx] = add (A[0] , A[1]);
                    ret = ret + A[idx];
                    idx = 1 - idx;
                }
                if (ret == num) return true;
            }
        }
        return false;
    }
};