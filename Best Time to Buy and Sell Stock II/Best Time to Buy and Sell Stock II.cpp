class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size ();
        vector <int> yes (n + 1 , INT_MIN) , no (n + 1 , 0);
        for (int i = 0 ; i < n ; i ++) {
            yes[i + 1] = max (yes[i] , no[i] - prices[i]);
            no[i + 1] = max (no[i] , yes[i] + prices[i]);
        }
        return no[n];
    }
};
