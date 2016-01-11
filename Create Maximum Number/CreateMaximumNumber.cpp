unsigned int ten[10];
class Solution {
public:
    inline void update (vector <unsigned int> &a , vector <unsigned int> b) {
        if (a.empty ()) a = b;
        else {
            for (int i = 1 ; i < (int)a.size () ; i ++) {
                if (b[i] > a[i]) {
                    a = b;
                    return;
                }
            }
        }
    }
    vector <unsigned int> dfs (vector <int> &a , vector<int> &b , int x , int y , int z) {
        if (!dp[x][y][z].empty ()) return dp[x][y][z];
        if (z == 0) {
            return vector <unsigned int> (1 , 0);
        }
        int n = (int)a.size () , m = (int)b.size () , mx = 0;
        for (int i = x ; i < n && n - i + m - y >= z ; i ++) {
            mx = max (mx , a[i]);
        }
        for (int j = y ; j < m && m - j + n - x >= z ; j ++) {
            mx = max (mx , b[j]);
        }
        vector <unsigned int> &ans = dp[x][y][z];
        for (int i = x ; i < n && n - i + m - y >= z ; i ++) {
            if (a[i] == mx) {
                update (ans , dfs (a , b , i + 1 , y , z - 1));
                break;
            }
        }
        for (int j = y ; j < m && m - j + n - x >= z ; j ++) {
            if (b[j] == mx) {
                update (ans , dfs (a , b , x , j + 1 , z - 1));
                break;
            }
        }
        if (ans[0] % 9 == 0) {
            ans.push_back (mx);
        }
        else {
            ans[ans[0] / 9 + 1] = ans[ans[0] / 9 + 1] + mx * ten[ans[0] % 9];
        }
        ans[0] ++;
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        ten[0] = 1;
        for (int i = 1 ; i < 10 ; i ++)
            ten[i] = ten[i - 1] * 10;
        int n = nums1.size () , m = nums2.size ();
        vector <vector <unsigned int> > one (k + 1 , vector <unsigned int> ());
        vector <vector <vector <unsigned int> > > two (m + 1 , one);
        dp.resize (n + 1 , two);
        vector <unsigned int> ans = dfs (nums1 , nums2 , 0 , 0 , k);
        vector <int> ret;
        while (k --) {
            ret.push_back (ans[k / 9 + 1] % 10);
            ans[k / 9 + 1] /= 10;
        }
        reverse (ret.begin () , ret.end ());
        return ret;
    }
private:
    vector <vector < vector <vector <unsigned int> > > > dp;
};
