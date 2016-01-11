class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = (int)cit.size ();
        int low = 0 , high = n , ans = -1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int unsmall = n - (lower_bound (cit.begin () , cit.end () , mid) - cit.begin ());
            if (unsmall >= mid) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
