class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size ();
        vector <int> ans;
        if (n == 0) return ans;
        deque <int> deq;
        for (int i = 0 ; i < k - 1 ; i ++) {
            while (!deq.empty () && nums[i] >= nums[deq.front ()]) {
                deq.pop_front ();
            }
            deq.push_front (i);
        }
        for (int i = k - 1 ; i < n ; i ++) {
            while (!deq.empty () && nums[i] >= nums[deq.front ()]) {
                deq.pop_front ();
            }
            deq.push_front (i);
            ans.push_back (nums[deq.back ()]);
            if (deq.back () == i - k + 1) {
                deq.pop_back ();
            }
        }
        return ans;
    }
};
