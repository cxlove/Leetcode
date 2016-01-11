class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size () , find = 0;
        for (int i = 0 ; i < n ; i ++) {
            if (nums[i] == n) {
                find = 1;
            }
            else {
                while (nums[nums[i]] > nums[i]) {
                    swap (nums[i] , nums[nums[i]]);
                    if (nums[i] == n) {
                        find = 1;
                        break;
                    }
                }
            }
        }
        if (!find) return n;
        for (int i = 0 ; i < n ; i ++) {
            if (nums[i] != i)
                return i;
        }
    }
};
