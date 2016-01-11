class Solution {
public:
    inline int get (vector <int>& nums , int i) {
        if (i < 0 || i >= (int)nums.size ()) return 1;
        return nums[i];
    }
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size ();
        if (n == 0) return 0;
        vector <vector <int> > dp = vector <vector <int> > (n , vector <int> (n , 0));
        for (int i = 0 ; i < n ; i ++) {
            dp[i][i] = get (nums , i - 1) * get (nums , i) * get (nums , i + 1);
        }
        for (int len = 1 ; len < n ; len ++) {
            for (int l = 0 ; l + len < n ; l ++) {
                int r = l + len;
                dp[l][r] = max (dp[l][r - 1] + get (nums , r) * get (nums , r + 1) * get (nums , l - 1) , \
                                dp[l + 1][r] + get (nums , l) * get (nums , l - 1) * get (nums , r + 1));
                for (int i = l + 1 ; i < r ; i ++) {
                    dp[l][r] = max (dp[l][r] , dp[l][i - 1] + dp[i + 1][r] + get (nums , i) * get (nums , l - 1) * get (nums , r + 1));
                }
            }
        }
        return dp[0][n - 1];
    }
};