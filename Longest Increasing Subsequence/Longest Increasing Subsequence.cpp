class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size ();
        if (n < 2) return n;
        vector <int> a;
        a.push_back (nums[0]);
        for (int i = 1 ; i < n ; i ++) {
            int p = lower_bound (a.begin () , a.end () , nums[i]) - a.begin ();
            if (p == (int)a.size ()) a.push_back (nums[i]);
            else a[p] = nums[i];
        }
        return (int)a.size ();
    }
};