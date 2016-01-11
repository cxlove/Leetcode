class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        stack <pair <int , int> > segment;
        vector <int> profit;
        for (vector <int> :: size_type low = 0 , high = -1 ; ;) {
            for (low = high + 1 ; low + 1 < prices.size () && prices[low] >= prices[low + 1] ; low ++);
            for (high = low ; high + 1 < prices.size () && prices[high] <= prices[high + 1] ; high ++);
            if (low == high) break;
            while (!segment.empty () && prices[low] <= prices[segment.top ().first]) {
                profit.push_back (prices[segment.top ().second] - prices[segment.top ().first]);
                segment.pop ();
            }
            
            while (!segment.empty () && prices[high] >= prices[segment.top ().second]) {
                profit.push_back (prices[segment.top ().second] - prices[low]);
                low = segment.top ().first;
                segment.pop ();
            }
            
            segment.push (make_pair (low , high));
        }
        
        while (!segment.empty ()) {
            profit.push_back (prices[segment.top ().second] - prices[segment.top ().first]);
            segment.pop ();
        }
        
        if (profit.size () <= k) {
            return accumulate (profit.begin () , profit.end () , 0);
        }
        else {
            nth_element (profit.begin () , profit.end () - k , profit.end ());
            return accumulate (profit.end () - k , profit.end () , 0);
        }
    }
};
