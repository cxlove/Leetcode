class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size ();
        if (n < 2) return 0;
        vector <vector <int> > dp (n , vector <int> (2 , 0));
        dp[0][0] = -prices[0];
        for (int i = 1 ; i < n ; i ++) {
            // sell
            dp[i][1] = max (dp[i - 1][1] , dp[i - 1][0] + prices[i]);
            // buy
            dp[i][0] = max (dp[i - 1][0] , -prices[i]);
            if (i >= 2) dp[i][0] = max (dp[i][0] , dp[i - 2][1] - prices[i]);
        }
        
        return dp[n - 1][1];
    }
};