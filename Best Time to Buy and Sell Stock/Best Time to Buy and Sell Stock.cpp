class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 , n = (int)prices.size ();
        if (n <= 1) return 0;
        int prefix = prices[0];
        for (int i = 1 ; i < n ; i ++) {
            ans = max (ans , prices[i] - prefix);
            prefix = min (prefix , prices[i]);
        }
        return ans;
    }
};
