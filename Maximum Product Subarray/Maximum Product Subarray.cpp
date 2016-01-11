class Solution {
public:
    inline int gao (vector<int>& nums , int l , int r) {
        if (l > r) return nums[0];
        if (l == r) return nums[l];
        int all = 1 , prefix = 1 , suffix = 1;
        for (int i = l ; i <= r ; i ++) {
            all *= nums[i];
        }
        if (all > 0) return all;
        for (int i = l , j = 1 ; i <= r ; i ++) {
            j *= nums[i];
            if (nums[i] < 0) {
                prefix = j;break;
            }
        }
        for (int i = r , j = 1 ; i >= l ; i --) {
            j *= nums[i];
            if (nums[i] < 0) {
                suffix = j;break;
            }
        }
        return max (all / prefix , all / suffix);
    }

    int maxProduct(vector<int>& nums) {
        int l = 0 , ans = nums[0];
        for (int i = 0 ; i < (int)nums.size () ; i ++) {
            if (nums[i] == 0) {
                ans = max (max (0 , ans) , gao (nums , l , i - 1));
                l = i + 1;
            }
        }
        ans = max (ans , gao (nums , l , (int)nums.size () - 1));
        return ans;
    }
};