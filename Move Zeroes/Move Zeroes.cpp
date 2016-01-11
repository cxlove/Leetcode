class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size ();
        int i = 0 , j = 0;
        while (true) {
            while (i < n && nums[i] != 0) i ++;
            j = min (n - 1 , max (j , i + 1));
            while (j < n && nums[j] == 0) j ++;
            if (i >= n || j >= n) break;
            swap (nums[i] , nums[j]);
            i ++;j ++;
        }
    }
};