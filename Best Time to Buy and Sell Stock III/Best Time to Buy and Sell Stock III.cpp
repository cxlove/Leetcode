class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size ();
        if (n < 2) return 0;
        vector <int> l (n , 0);
        vector <int> r (n , 0);
        for (int i = 1 , prefix = prices[0] ; i < n ; i ++) {
            l[i] = max (l[i - 1] , prices[i] - prefix);
            prefix = min (prefix , prices[i]);
        }
        for (int i = n - 2 , suffix = prices[n - 1] ; i >= 0 ; i --) {
            r[i] = max (r[i + 1] , suffix - prices[i]);
            suffix = max (suffix , prices[i]);
        }
        int ans = l[n - 1];
        for (int i = 1 ; i < n - 1 ; i ++) {
        }
        return ans;
    }
};
